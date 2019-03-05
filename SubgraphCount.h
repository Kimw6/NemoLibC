/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   SubgraphCount.h
 * Author: Wooyoung
 *
 * Created on October 18, 2017, 4:39 PM
 */

#ifndef SUBGRAPHCOUNT_H
#define SUBGRAPHCOUNT_H
#include "SubgraphEnumerationResult.h"

/*Test sparse hash map*/



/**
 * Representation of a Subgraph Count structure, which stores the number of
 * subgraphs detected in a network separated by subgraph type. A SubgraphCount
 * object exists in one of two states: labeled and unlabeled. Certain 
 * operations can only be performed based on the Subgraph's labeled state.
 */


class SubgraphCount: public SubgraphEnumerationResult {
    friend ostream& operator<< (ostream&, const SubgraphCount&);
public:
    /**
	 * Construct an empty SubgraphCount. Create an sparse_hash_map (like a hash map)
	 */
    SubgraphCount();
    virtual ~SubgraphCount();
    /* Implement the add function of subgraph enumeration result*/
    void add(Subgraph&, NautyLink&); 
     
    unordered_map <graph64, double> getRelativeFrequencies();    
     
    unordered_map <graph64, uint64> getlabeFreqMap();  
    
 
    
    bool equals(SubgraphCount&); // not implemented yet
    
private:
    unordered_map<graph64, uint64> labelFreqMap; 
    
        


};

#endif /* SUBGRAPHCOUNT_H */

