/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ESU.cpp
 * Author: Wooyoung
 * 
 * Created on October 25, 2017, 1:06 PM
 */

#include "ESU.h"

void ESU::enumerate(Graph& graph, SubgraphEnumerationResult& subgraphs, int subgraphSize) {
    
    
    NautyLink nautylink(subgraphSize, graph.getEdges(), graph.isDirected());
    for (int i = 0; i < graph.getSize(); i++) {
        enumerate(graph, subgraphs, subgraphSize, i, nautylink);
    }
}

void ESU::enumerate(Graph& graph, SubgraphEnumerationResult& subgraphs, int subgraphSize, vertex vertexV, NautyLink& nautylink) {
  
    vector<double> probs;
    for (int i = 0; i < subgraphSize; ++i) {
        probs.push_back(1.0);
    }
    
    RandESU::enumerate(graph, subgraphs, subgraphSize, probs, vertexV, nautylink);
}

