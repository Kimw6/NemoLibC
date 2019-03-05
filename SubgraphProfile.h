/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubgraphProfile.h
 * Author: Wooyoung
 *
 * Created on October 29, 2017, 3:05 PM
 */

#ifndef SUBGRAPHPROFILE_H
#define SUBGRAPHPROFILE_H

#include "SubgraphEnumerationResult.h"
// The primary structure of a subgraph profile. Essentially a table to map 
	// labels(String) and nodes(Integer) to the frequency of subgraphs 
	// of type label that include the node.

/* This class will have two maps: subgraphprofile and subgraphcount map */
class SubgraphProfile:public SubgraphEnumerationResult {
public:
    // get the size of vertex as parameter
    SubgraphProfile(uint64); 
    virtual ~SubgraphProfile();
    void add(Subgraph&, NautyLink&); 
      
    unordered_map <graph64, double> getRelativeFrequencies();
    unordered_map<graph64, vector<uint64>> getlabelVertexFreqMapMap();
    unordered_map<graph64, uint64> getlabelFreqMap(int); //need subgraphsize to calculate frequency
    /**
	 * Merge this SubgraphProfile with another SubgraphProfile
	 * @param other the other SubgraphProfile to merge with this 
	 * SubgraphProfile
	 */
    void merge();
private:
    unordered_map<graph64, vector<uint64>> labelVertexFreqMapMap;
    uint64 getTotalSubgaphCount();
    uint64 graphsize;


};

#endif /* SUBGRAPHPROFILE_H */

