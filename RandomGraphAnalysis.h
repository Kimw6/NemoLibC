/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomGraphAnalysis.h
 * Author: Wooyoung
 *
 * Created on November 3, 2017, 1:29 PM
 */

/**
 * RandomGraphAnalysis is a facade class that generates and enumerates using
 * RAND-ESU a set of random network graphs based on the degree sequence vector
 * of a specified graph. The output of the analyze() method can be used by a
 * StatisticalAnalysis object to determine whether a target graph contains any
 * network motifs.
 */

#ifndef RANDOMGRAPHANALYSIS_H
#define RANDOMGRAPHANALYSIS_H

#include "SubgraphCount.h"
#include "RandomGraphGenerator.h"
#include "RandESU.h"
#include <vector>
#include <algorithm>
using std::vector;

class RandomGraphAnalysis {
public:
    RandomGraphAnalysis();
    virtual ~RandomGraphAnalysis();
    static unordered_map<graph64, vector<double>> analyze(Graph&, int, int, const vector<double>&);  
        
    
private:

};

#endif /* RANDOMGRAPHANALYSIS_H */

