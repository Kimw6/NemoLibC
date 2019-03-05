/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NautyLink.h
 * Author: Wooyoung
 *
 * Created on October 27, 2017, 11:36 AM
 */
#ifndef NAUTYLINK_H
#define NAUTYLINK_H

#include <iostream>
#include <fstream>
using std::cout;
using std::cerr;
using std::endl;
#include <vector>
using std::vector;
#include <stdexcept>
using std::domain_error;
#include <string>
using std::string;




#include <unordered_map> // Like a hash_map. It should be compiled with -std=c++11 option. 
using std::unordered_map;

#define MAXN 64
#include <string.h>
#include <stdio.h>
#include <math.h>
//#include "gtools.h"
#include "nauty/nauty.h"
#include "graph64.hpp"
#include "Subgraph.h"
#include "nauty/nautinv.h"


typedef uint64 graph64;//Nauty label

class NautyLink {
public:
    NautyLink(int, unordered_map<edge, edgetype>);
     NautyLink(int, unordered_map<edge, edgetype>, bool);
    virtual ~NautyLink();
    void nautyinit();
    int get_G_N();
    int get_G_M();
    graph64 nautylabel(Subgraph&);
    
private:
    bool directed;
    graph64 getLabel(graph*, set*, const int, const int);
    int G_N; // subgraphsize
    int G_M;
    graph canon[MAXN * MAXM]; 
    graph nautyGraph[MAXN * MAXM];
    int lab[MAXN];
    int ptn[MAXN];
    int orbits[MAXN];
    setword workspace[160 * MAXM]; 
    set *gv = NULL;
    
    //added
    
    DEFAULTOPTIONS(options);
    statsblk(stats); 
    unordered_map<edge, edgetype> edges; // get the edges when initialize it    
    
 
    
};

#endif /* NAUTYLINK_H */

