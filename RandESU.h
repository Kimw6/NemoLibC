/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandESU.h
 * Author: Wooyoung
 *
 * Created on October 25, 2017, 10:28 AM
 */

/**
 * RandESU is a static class used for executing the RandESU on a portion of a
 * network graph.
 */

#ifndef RANDESU_H
#define RANDESU_H
#include "Graph.h"
#include "Subgraph.h"
#include "SubgraphEnumerationResult.h"
#include <stdexcept> // to throw invalid_argument
#include <vector>
//#include <set>
//using std::set;

#include <math.h> 
#include <algorithm>
#include "NautyLink.h"

#include <unordered_set>
using std::unordered_set;


using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::domain_error;
using std::string;
//using std::unordered_map;

class RandESU {
public:
    /**
	 * Enumerates all subgraphSize Subgraphs in the input Graph using the 
	 * RAND-ESU algorithm.
	 *
	 * @param graph           the graph on which to execute RAND-ESU
	 * @param subgraphSize    the size of the target Subgraphs
	 */
    static void enumerate(Graph&, SubgraphEnumerationResult&, int, const vector<double>);
    /**
	 * Enumerates all subgraphSize Subgraphs for the specified vertice's branch
	 * of an ESU execution tree using the RAND-ESU algorithm. Allows for more
	 * control over execution order compared to the enumerate method that does
	 * not include a vertex parameter.
	 * @param graph the graph on which to execute RAND-ESU
	 * @param subgraphs
	 * @param subgraphSize
	 * @param probs
	 * @param vertex
         * @param nuatylink
	 */
    static void enumerate(Graph&, SubgraphEnumerationResult&, int, const vector<double>, vertex, NautyLink&);
    
    
        
private:
    
    /** determines whether or not to extend based on a given probability, given
	 as an integer.
	 precondition: 0.0 <= prob <= 1.0
    **/
    static bool shouldExtend(double);
    
    /** returns true if the node index is exclusive to the given subgraph
	 (that is, is not already in the subgraph, and is not adjacent to any of
	  the nodes in the subgraph)
     **/
    
    static bool isExclusive(Graph&, vertex, Subgraph&);
    
       /** extend the subgraphs recursively    
     * */
    static void extend(Graph&, Subgraph&, vector<vertex>, const vector<double>, SubgraphEnumerationResult&, NautyLink&);
 

};

#endif /* RANDESU_H */

