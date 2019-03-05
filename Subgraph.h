/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Subgraph.h
 * Author: Wooyoung
 *
 * Created on October 23, 2017, 2:34 PM
 * Note that this Subgraph class is different from Java version, where the adjacentmatrix is necessary
 * It will inherit most of the functions from Graph 
 * 
 */

#ifndef SUBGRAPH_H
#define SUBGRAPH_H




#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

#include <vector>
using std::vector;


#include "graph64.hpp"


class Subgraph {
   friend ostream& operator<< (ostream&, const Subgraph&);
public:
    Subgraph(int); /// the order of this subgraphs
    virtual ~Subgraph();
    Subgraph copy();
    int getSize();
    int getOrder();
    int root(); //get the first vertex id added to this subgraph
    bool contains(vertex); //Check whether a vertex exists in this Subgraph
    void add(vertex);
    int get(int); //get the nth node of this subgraph
    vector<vertex>& getNodes();
    bool isComplete();
    
private:
    vector<vertex> nodes; // get the list of vertex lists
    int order; // the intended size
 };

#endif /* SUBGRAPH_H */

