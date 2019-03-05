/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubgraphCount.cpp
 * Author: Wooyoung
 * 
 * Created on October 18, 2017, 4:39 PM
 */

#include "SubgraphCount.h"



/**
	 * Construct an empty SubgraphCount.
	 */
SubgraphCount::SubgraphCount(){
    // labeFreqMap initialize (already done)
}

SubgraphCount::~SubgraphCount(){
    
}
/* Add subgraphs using label
 * Just to check, we will implement without labeling yet
 */
void SubgraphCount::add(Subgraph& currentSubgraph, NautyLink& nautylink){
 
   graph64 label=nautylink.nautylabel(currentSubgraph);
    
   
   uint64 total = 0;
  
   
if(labelFreqMap.count(label)>0) total = labelFreqMap[label];
   
   labelFreqMap[label]=++total; 
   
    
   
}

unordered_map<graph64, uint64> SubgraphCount::getlabeFreqMap(){
    return labelFreqMap;
}

// it might not need in c++ as we directly compute the 

/* Get the relative frequencies instead of count*/
unordered_map <graph64, double> SubgraphCount::getRelativeFrequencies(){
    uint64 totalSubgraphCount=0;
    unordered_map<graph64, double> result_map;
    for (auto& p:labelFreqMap){
//        totalSubgraphCount +=labelFreqMap.at(p.first);
        totalSubgraphCount +=labelFreqMap[p.first];
    }
    
    for (auto& p:labelFreqMap){
  //      uint64 count = labelFreqMap.at(p.first);
        uint64 count = labelFreqMap[p.first];
        double freq = (double) count/totalSubgraphCount;
        //result_map.insert({p.first,freq} );        
        result_map[p.first]=freq;
    }
    return result_map;
}

