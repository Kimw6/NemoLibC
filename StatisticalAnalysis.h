/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   StatisticalAnalysis.h
 * Author: Wooyoung
 *
 * Created on November 3, 2017, 2:32 PM
 */

#ifndef STATISTICALANALYSIS_H
#define STATISTICALANALYSIS_H

#include "RandomGraphAnalysis.h"
#include <cmath>
using std::pow;
using std::sqrt;

#include <string>
using std::string;
#include <sstream>
using std::stringstream;

#include <iomanip>
using std::setprecision;

class StatisticalAnalysis {
    
     friend ostream& operator<< (ostream&, StatisticalAnalysis&);
     
public:
    StatisticalAnalysis(); // not allowed
    StatisticalAnalysis(unordered_map<graph64, double>&, unordered_map<graph64, vector<double>>& ,int);
    virtual ~StatisticalAnalysis();
    
    unordered_map<graph64, double> getZScores();
    double getZScore(graph64);
    double getZScore(graph64, double, double);
    unordered_map<graph64, double> getPValues();
    double getPValue(graph64);    
    
    int randGraphCount;
    
private:
    unordered_map<graph64, double> targetGraphRelFreqs;
    unordered_map<graph64, vector<double>> randomGraphRelFreqs;
    double calcRandStdDev(graph64, double);
    double calcRandMean(graph64);
    
    
    

};

#endif /* STATISTICALANALYSIS_H */

