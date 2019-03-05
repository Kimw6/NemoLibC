/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubgraphProfile.cpp
 * Author: Wooyoung
 * 
 * Created on October 29, 2017, 3:05 PM
 */

#include "SubgraphProfile.h"
using std::cout;
using std::ostream;

//need the subgraphsize to compute subgraphcount for each label

SubgraphProfile::SubgraphProfile(uint64 graphSize) {
    graphsize = graphSize;
    cout<<"subgraphprofile"<<endl;
    
}


SubgraphProfile::~SubgraphProfile() {
    graphsize = 0;
}
/* Add subgraphs using label
 * Just to check, we will implement without labeling yet
 */
void SubgraphProfile::add(Subgraph& currentSubgraph, NautyLink& nautylink) {

    // first, get the label
    graph64 label = nautylink.nautylabel(currentSubgraph);

    // get the current nodes
    vector<vertex> nodes = currentSubgraph.getNodes();
    
    // vector that stores the frequency
    vector<uint64> nodeFreqMap(graphsize,0);

    // if the key already exists, then update
    if (labelVertexFreqMapMap.count(label)>0)
        nodeFreqMap = labelVertexFreqMapMap[label];

    // update the map
    for (int i = 0; i < currentSubgraph.getSize(); i++) {
        vertex currentNode = nodes[i];
         nodeFreqMap[currentNode]++;        
    }
    
    //update the final map
    labelVertexFreqMapMap[label] = nodeFreqMap;
}


 unordered_map<graph64, vector<uint64>> SubgraphProfile::getlabelVertexFreqMapMap(){
     return labelVertexFreqMapMap;
 }
 
 unordered_map<graph64, uint64> SubgraphProfile::getlabelFreqMap(int subgraphsize){
     unordered_map <graph64, uint64> labelFreqMap;
     uint64 totalcount = getTotalSubgaphCount();
      for (auto& p:labelVertexFreqMapMap ){
          uint64 countLabel =0;
          vector<uint64> vertexmap = p.second;
          for (auto&q:vertexmap)
              countLabel+=q;
          labelFreqMap[p.first]= countLabel/subgraphsize;  
      }
     return labelFreqMap;
 }
 
 unordered_map <graph64, double> SubgraphProfile::getRelativeFrequencies(){
     
     unordered_map<graph64, double> result;
     double totalSubgraphCount = (double) getTotalSubgaphCount();
     
     int totalcount = getTotalSubgaphCount();
      for (auto& p:labelVertexFreqMapMap ){
          double countLabel =0;
          vector<uint64> vertexmap = p.second;
          for (auto&q:vertexmap)
              countLabel+=q;
          result[p.first]= countLabel/totalSubgraphCount;  
      }
     return result;
     
     
 }
 
 uint64 SubgraphProfile::getTotalSubgaphCount(){
     int totalcount = 0;
     for (auto& p:labelVertexFreqMapMap ){
        vector <uint64> vertexmap = p.second;
        for (const auto& q : vertexmap)
            totalcount +=q;
     }
     return totalcount;
     
 }
 