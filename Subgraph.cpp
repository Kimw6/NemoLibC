/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Subgraph.cpp
 * Author: Wooyoung
 * 
 * Created on October 23, 2017, 2:34 PM
 */



#include "Subgraph.h"


 /**
	 * Construct a subgraph of a specified order (i.e. number of nodes)
	 * @param order the order of this subgraphs
	 */


Subgraph::Subgraph(int order){
    this->order = order; 
}

Subgraph::~Subgraph(){
     this->order = 0;
}
/**
	 * Create a deep copy of this subgraph
	 * @return a deep copy of this subgraph
	 */

Subgraph Subgraph::copy(){
    Subgraph copy(order);
    copy.order = order;
    for (int i=0; i<nodes.size();i++){
        copy.nodes.push_back(nodes.at(i));
    }
    return copy;
}

/**
	 * Get the current size of this Subgraph.
	 * @return the size of this Subgraph.
	 */ 


int Subgraph::getSize(){
    return nodes.size();
}

/**
	 * Get number of possible nodes in this Subgraph
	 * @return the maximum order of this Subgraph
	 */


int Subgraph::getOrder(){
    return order;
}
/**
	 * Test whether this subgraph has been filled
	 * @return true if subgraph is full; false otherwise
	 */

bool Subgraph::isComplete(){
    return (nodes.size() == order);
}
/**
 * Gets the id number of the first vertex added to this Subgraph
 * @return the id of the root
 */

int Subgraph::root() {
    if (nodes.size()<1) {
       cout<< "It is currently empty"<<endl;
        return -1;    
    }
    return nodes.at(0);
}
    
/**
 * Check whether a vertex exists in this Subgraph
 * @param vertex the target vertex
 * @return true if this subgraph contains the specified vertex, false
 * otherwise
 */


bool Subgraph::contains(vertex v) {  
        
    for (int i = 0; i < nodes.size(); i++) {
        if (nodes.at(i) == v) {
            return true;
        }
    }
    return false;
}

/**
 * Add a vertex to this Subgraph
 * @param vertex the vertex to add to this Subgraph
 * @param adjacencyList the adjacencyList of the vertex being added
 * @precondition: cannot add if the subgraph is complete
 */

void Subgraph::add(vertex v) {
    if(isComplete()){
        cout<<"The subgraph is full:: Cannot add more"<<endl;
       return;
    }
   
    nodes.push_back(v);
    
}
/**
 * Get the nth node added to this Subgraph
 * @return the nth node added to this Subgraph
 */


int Subgraph::get(int n) {
    if((n>nodes.size()-1)||(nodes.size()<1)){
        cout<<n<<"th index is not available"<<endl;
        return -1;
    }
    return nodes.at(n);
}
/**
 * Get all the nodes in this Subgraph
 * @return this Subgraph's nodes
 */


vector<vertex>& Subgraph::getNodes() {
    return nodes;
}

/**
	 * Return a string representation of this Subgraph. Should display in the 
	 * format [x, y, z], where x, y, and z represent vertices in this subgraph.
	 * @return a string representation of this subgraph
	 */



 ostream& operator<<(ostream& out, const Subgraph& sgraph) {
     string s = "[";
     if (sgraph.nodes.size()<1) {
         out<<"empty";
         return out;
     }
         
     for (int i=0; i<sgraph.nodes.size()-1; i++){
         stringstream ss;
         ss<<sgraph.nodes.at(i);
         s = s+ss.str()+",";
     }
     stringstream last;
     last<<sgraph.nodes.at(sgraph.nodes.size()-1);
     s = s+last.str()+"]";

    out << s;

    return out;

}

 
 
