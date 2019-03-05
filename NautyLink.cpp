/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NautyLink.cpp
 * Author: Wooyoung
 * 
 * Created on October 27, 2017, 11:36 AM
 */

#include "NautyLink.h"

NautyLink::NautyLink(int subgraphsize, unordered_map<edge, edgetype> edgeset):NautyLink(subgraphsize, edgeset, false)  {

}

NautyLink::NautyLink(int subgraphsize, unordered_map<edge, edgetype> edgeset, bool dir) {
    G_N=subgraphsize;
    directed=dir;
    nautyinit();
    edges = edgeset;
}


NautyLink::~NautyLink() {
}

int NautyLink::get_G_N(){
    return G_N;
}

graph64 NautyLink::getLabel(graph* canon, set* gv, const int G_N, const int G_M)
{

      //Fanmod code to retrieve canon data
    graph64 res_gr = 0ULL;
    for (int a = 0; a < G_N; ++a) 
    {
        gv = GRAPHROW(canon, a, G_M);
	    for (int b = 0; b < G_N; ++b) 
        {
		    res_gr <<= 1;
		    if (ISELEMENT(gv, b))
            {
		        res_gr |= 1;
		    }
	    }
    }
    return res_gr;
        
}

void NautyLink::nautyinit(){
 
    G_M = (G_N + WORDSIZE - 1) / WORDSIZE; //#define WORDSIZE 64
    
    options.writeautoms = FALSE;
    options.getcanon = TRUE;
    
    if (directed) {
		options.digraph = TRUE;
		options.invarproc = adjacencies;
		options.mininvarlevel = 1;
		options.maxinvarlevel = 10;
    }
    
    // Initialize nautyGraph
    for (int i = 0; i != G_N; ++i) {

        EMPTYSET(GRAPHROW(nautyGraph, i, G_M), G_M);
    }    
    
        nauty_check(WORDSIZE, G_M, G_N, NAUTYVERSIONID);  
}
/* For each subgraph, return its cannonical label */
graph64 NautyLink::nautylabel(Subgraph& subgraph){
      
    
    // get the node(index) list from subgraph
     int subsize = subgraph.getSize();
    
    // get the adjacenylists of the node(index) list from subgraph
    // key = node id. value = the adjacencylist of the node (key)
    
    //go through each pair from nodes and connect if there is an edge
    for (int i = 0; i < subsize ; i++) {
        for (int j = 0; j < subsize ; j++) {
            if (i != j) {
                vertex uc = subgraph.get(i);
                vertex vc = subgraph.get(j);
                edge e_check = edge_code(uc, vc);
                //if there is an edge between nodes[i] and nodes[j], connect i and j 
                if (edges.count(e_check) > 0) {
                    edgetype ec = edges[e_check];
                    if (((uc < vc) && (ec == DIR_U_T_V)) || ((uc > vc) && (ec == DIR_V_T_U))) {
                       // cout<<"1. connect "<<uc<<" and "<<vc<<endl;
                        DELELEMENT(GRAPHROW(nautyGraph, i, G_M), j);
                        gv = GRAPHROW(nautyGraph, i, G_M);
                        ADDELEMENT(gv, j);
                    } /*else if (((uc < vc) && (ec == DIR_V_T_U)) || ((uc > vc) && (ec == DIR_U_T_V))) {
                         cout<<"2. connect "<<vc<<" and "<<uc<<endl;
                        DELELEMENT(GRAPHROW(nautyGraph, j, G_M), i);
                        gv = GRAPHROW(nautyGraph, j, G_M);
                        ADDELEMENT(gv, i);
                    }*/ else if (ec == UNDIR_U_V) {
                     //    cout<<"3. connect "<<uc<<" and "<<vc<<endl;
                        DELELEMENT(GRAPHROW(nautyGraph, i, G_M), j);
                        gv = GRAPHROW(nautyGraph, i, G_M);
                        ADDELEMENT(gv, j);
                    }
                }
            }
        }
    }
    
    nauty(nautyGraph, lab, ptn, NILSET, orbits, &options, &stats, workspace, 160 * MAXM, G_M, G_N, canon); 
    
    // get the cannonical label 
    graph64 res_gr = getLabel(canon, gv,G_N, G_M);
    
    // then initialize the graph
     for (int i = 0; i != G_N; ++i) {

        EMPTYSET(GRAPHROW(nautyGraph, i, G_M), G_M);
    }
    
    return res_gr;
}

