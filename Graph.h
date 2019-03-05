/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.h
 * Author: Wooyoung
 *
 * Created on October 12, 2017, 1:51 PM
 */

#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;

#include <stdexcept> // to throw invalid_argument
#include <string>
using std::string;
#include <sstream>
using std::stringstream;
#include <vector>


#include <unordered_map> // Like a hash_map. It should be compiled with -std=c++11 option. 
using std::unordered_map;
#include <unordered_set> // Like a hash_set. It should be compiled with -std=c++11 option. 
using std::unordered_set;



#include <fstream>
using std::ifstream;
#include <algorithm>    // std::random_shuffle

using std::cout;
using std::ostream;
using std::vector;

using std::domain_error;
using std::invalid_argument;
using std::random_shuffle;



// need to store the adjacency list as ordered set


#include "graph64.hpp"


class Graph {
     friend ostream& operator<< (ostream&, const Graph&);
    
    
public:
    Graph(); // default constructor which creates an undirected graph
    Graph(bool);//constructor with directed/or undirected
    Graph(string); //undirected graph constructor with a filename
    Graph(string, bool);//undirected graph with 
    virtual ~Graph();    
    int addVertex(string);
    int addVertex(); //used to generate a random graph
    bool addEdge(vertex, vertex);
    int getSize();
    bool isDirected();
    unordered_set<vertex>& getAdjacencyList(vertex);

    
    unordered_map <string, vertex>& getNametoIndex();
    unordered_map<vertex, string> getIndextoName(); // will be useful if need to match the index to name
   unordered_map < edge, edgetype > getEdges();; // added by following the original ESU program

 
   
   // might not need--> will delete later
    class Edge{
        friend ostream& operator<< (ostream&, Graph::Edge&);
        private:
            vertex nodeA;
            vertex nodeB;
        public:
            Edge();
            Edge(vertex, vertex);
            bool equals(Edge&, bool);  // added bool parameter to indicate the graph's directedness
    };
    
    
private:
    /*This is a set of adjacencylist of a graph (directed or undirected)*/
    vector< unordered_set <vertex> > adjacencyLists;
    
    /*For directed graph, editing nauty graph is different from undirected graph. Therefore, it needs a separate structure*/
    
  //  vector<unordered_set <vertex> > dir_adjacencyLists; // this is only for directed graph (might not need)
    
    void parse(string);
    vertex getOrCreateIndex(string, unordered_map<string, vertex>&);
         /**
	 * name2Index as a hashmap so key is a node name (string) and value is its index. Will be used when graph is read from file
	 */
    unordered_map<string, vertex> name2Index;
    bool directed; // added by WK (10/18/2017)       
    unordered_map < edge, edgetype > edges; // added by following the original ESU program

    
    
    

};

#endif /* GRAPH_H */

