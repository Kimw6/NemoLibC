/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticalAnalysis.cpp
 * Author: Wooyoung
 * 
 * Created on November 3, 2017, 2:32 PM
 */

#include "StatisticalAnalysis.h"

/**
 * Subsystem to store relative frequencies for each subgraph pattern / label and
 * calculate the p-values and z-scores for those labels.
 */

StatisticalAnalysis::StatisticalAnalysis() { //not used
}



StatisticalAnalysis::~StatisticalAnalysis() {
}

StatisticalAnalysis::StatisticalAnalysis(unordered_map<graph64, double>& targetGraphRelFreqsMap,
        unordered_map<graph64, vector<double>>& randomGraphRelFreqsMap,
        int randGraphCount) {
    this->targetGraphRelFreqs = targetGraphRelFreqsMap;
    this->randomGraphRelFreqs = randomGraphRelFreqsMap;
    this->randGraphCount = randGraphCount;
}

unordered_map<graph64, double> StatisticalAnalysis::getZScores() {
    unordered_map<graph64, double> zScores;
    for (auto& p : randomGraphRelFreqs) {
         graph64 label = p.first;
        double randMean = calcRandMean(label);
        double randStdDev = calcRandStdDev(label, randMean);
        double targetGraphFreq = 0.0;
        if (targetGraphRelFreqs.count(label)>0) {
            targetGraphFreq = targetGraphRelFreqs[label];
        }
        double zScore = 0.0;
        if (randStdDev != 0) {
            zScore = (targetGraphFreq - randMean) / randStdDev;
        }
        zScores[label]=zScore;
    }
    return zScores;
}

double StatisticalAnalysis::getZScore(graph64 label) {
    double randMean = calcRandMean(label);
    double randStdDev = calcRandStdDev(label, randMean);
    return getZScore(label, randMean, randStdDev);
}

double StatisticalAnalysis::getZScore(graph64 label, double mean, double stdDev) {

    double targetGraphFreq = 0.0;
    if (targetGraphRelFreqs.count(label)>0) {
        targetGraphFreq = targetGraphRelFreqs[label];
    }
    double zScore = 0.0;
    if (stdDev != 0) {
        zScore = (targetGraphFreq - mean) / stdDev;
    }
    return zScore;
}

double StatisticalAnalysis::calcRandStdDev(graph64 label, double randMean) {
    double variance = 0.0;
    for (double randFreq : randomGraphRelFreqs[label]) {
        double distance = randFreq - randMean;
        double squaredDistance = pow(distance, 2);
        variance += squaredDistance;
    }
    return sqrt(variance / (randGraphCount - 1));
}

unordered_map<graph64, double> StatisticalAnalysis::getPValues() {
    unordered_map<graph64, double>  pValues;
     for (auto& p : randomGraphRelFreqs) {
         graph64 label = p.first;
        double pValue = getPValue(label);
        pValues[label]=pValue;
    }
    return pValues;
}

double StatisticalAnalysis::getPValue(graph64 label) {

    // if a label appears in the target graph that didn't show up in any
    // random graphs, clearly it's a network motif. This scenario shouldn't
    // happen for a reasonable number of random graphs
    if (randomGraphRelFreqs.count(label)<1) {
        return 0;
    }

    // This shouldn't happen with the current design, but in case the design
    // changes to include functionality to display all labels found in the
    // random graphs instead of just those in the target graph, this will
    // ensure those labels are not identified as network motifs
    if (targetGraphRelFreqs.count(label)<1) {
        return 1;
    }


    int prePValue = 0;
    vector<double> randFreqs = randomGraphRelFreqs[label];
    double targetFreq = targetGraphRelFreqs[label];
    for (double randFreq : randFreqs) {
        // if randFreq >= targetFreq
        if (randFreq >= targetFreq) {
            prePValue++;
        }
    }
    double randFreqCount = randFreqs.size();
    double pValue = (double) prePValue / randFreqCount;
    return pValue;
}

double StatisticalAnalysis::calcRandMean(graph64 label) {
    double total = 0.0;
    vector<double> relFreqs = randomGraphRelFreqs[label];
    if (relFreqs.size()<1) {
        return 0;
    }
    for (double randFreq : relFreqs) {
        total += randFreq;
    }
    return total / (double) relFreqs.size();
}

ostream& operator<<(ostream& out, StatisticalAnalysis& rstat) {
    
     out<< "Label\tRelFreq\t\tMean\t\tStDev\t\tZ-Score\t\tP-Value\n";
     out.precision(3);
     
     
     for (auto& p : rstat.randomGraphRelFreqs) {
         graph64 label = p.first;
         out<<label<<"\t";
         if (rstat.targetGraphRelFreqs.count(label)>0){
             double targetGraphRelFreqPerc = rstat.targetGraphRelFreqs[label];
             targetGraphRelFreqPerc=targetGraphRelFreqPerc*100.0;
             out<<std::fixed<<targetGraphRelFreqPerc;
         }
         else out<<0.000;
         
         out<<"%\t\t";
         double mean = rstat.calcRandMean(label);
         out<<mean*100<<"%\t\t";
         double stDev = rstat.calcRandStdDev(label, mean);
         out<<stDev<<"\t\t";
         double zScore = rstat.getZScore(label, mean, stDev);
         out<<zScore<<"\t\t";
         double pValue = rstat.getPValue(label);
         out<<pValue<<"\n";
         
         
     }
     
     return out;
   
     
    
    
}