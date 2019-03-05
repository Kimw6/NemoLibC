/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomGraphGenerator.h
 * Author: Wooyoung
 *
 * Created on November 2, 2017, 1:22 PM
 */



#ifndef RANDOMGRAPHGENERATOR_H
#define RANDOMGRAPHGENERATOR_H

#include "Graph.h"

/**
  * Generates random graphs from an input graph based on the degree sequence of 
  * the original graph.
  */

class RandomGraphGenerator {
public:
    RandomGraphGenerator();
    virtual ~RandomGraphGenerator();
    static Graph generate(Graph&);
    static Graph generate(Graph&, vector<int> );

private:
    static vector<int> getDegreeSequenceVector(Graph&);          

};

#endif /* RANDOMGRAPHGENERATOR_H */

