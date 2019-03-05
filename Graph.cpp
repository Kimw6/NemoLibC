/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Graph.cpp
 * Author: Wooyoung
 * 
 * Created on October 12, 2017, 1:51 PM
 */

#include "Graph.h"

Graph::Graph():Graph(false) {
}

Graph::Graph(bool dir){
    directed = dir; 
}


Graph::Graph(string filename):Graph(filename, false){
}

Graph::Graph(string filename, bool dir){
     directed = dir;
    parse(filename);
 
}


Graph::~Graph() {    
}
/**
 * Add a vertex to this Graph.
 * @return the ID number assigned to the new vertex
 */


int Graph::addVertex(string nodeName){
    unordered_map<string, vertex> nameToIndex;
    nameToIndex = name2Index;
    
    if (nameToIndex.count(nodeName)>0){
         cout<<"Same node already exists"<<endl;
         return -1;
    }
       
    vertex index = (vertex)adjacencyLists.size();
    nameToIndex[nodeName] = index;

    adjacencyLists.push_back(unordered_set<vertex> ());
    name2Index = nameToIndex; 
    
    return adjacencyLists.size()-1;   
    
    
}

// This function is used when generating random graphs

int Graph::addVertex(){
    adjacencyLists.push_back(unordered_set<vertex> ());
 
    return adjacencyLists.size()-1; 
    
    
}
/**
    * Add an edge between two existing vertices on this graph.
    * @param vertexA One of the vertices between which to add an edge.
    * @param vertexB The other vertex.
    * @return true if both vertexA and vertexB exist in this Graph; false
    * otherwise.
 */


bool Graph::addEdge(vertex vertexA, vertex vertexB){
    if (vertexA>adjacencyLists.size() -1 || vertexB> adjacencyLists.size()-1){
        return false;
    }
    else
    { // add edges for both direction
       adjacencyLists.at(vertexA).insert(vertexB);
       adjacencyLists.at(vertexB).insert(vertexA); 
       
       edge e=0;
        if(vertexA<vertexB){
            e = new_edge(vertexA, vertexB);
            if(directed) edges[e]=DIR_U_T_V;
            else edges[e]=UNDIR_U_V;
        }
        else{ // vertexB<vertexA
            e=new_edge(vertexB, vertexA);
            if(directed) edges[e]=DIR_V_T_U;
            else edges[e]=UNDIR_U_V;            
        }      
     
        return true;
       
    }
    
}
  // get the number of nodes in the graph
int Graph::getSize(){
    return adjacencyLists.size();
    
}

bool Graph::isDirected(){
    return directed;
}

 unordered_map < edge, edgetype > Graph::getEdges(){
     return edges;
 }
// get the adjacency list for a given node
unordered_set<vertex>& Graph::getAdjacencyList(vertex index){
    return adjacencyLists.at(index);
    
    
}


unordered_map<string, vertex>& Graph::getNametoIndex(){
    
           return name2Index;

}

unordered_map<vertex, string> Graph::getIndextoName() {

    unordered_map<vertex, string> Index2name;
    for (auto v : name2Index) {
        Index2name[v.second] = v.first;
    }

    return Index2name;

}


// parses a data file into an adjacency list representing the graph

void Graph::parse(string filename) {

    unordered_map<string, vertex> nameToIndex;

    // we read in all the data at once only so we can easily randomize it
    // with Collections.shuffle()
    ifstream in(filename);
    if (!in) {
        throw invalid_argument("Cannot find an input file");
    }
    vector<string> lines;
    string currentline;
    while (in) {
        getline(in, currentline); //read each line
        if (!currentline.empty()) lines.push_back(currentline);
    }

    in.close();
    // avoid clustering (data collection bias) by randomly parsing the
    // input lines of data

    random_shuffle(lines.begin(), lines.end());

    for (string line : lines) {
        string from, to;
        stringstream linesplits(line);
        linesplits >> from >> to;
        vertex fromIndex = getOrCreateIndex(from, nameToIndex);
        vertex toIndex = getOrCreateIndex(to, nameToIndex);
 
        // don't add self edges
        if (fromIndex == toIndex) continue;

        getAdjacencyList(fromIndex).insert(toIndex);
        getAdjacencyList(toIndex).insert(fromIndex);
//        if (directed) getDirAdjacencyList(fromIndex).insert(toIndex);
        
        // now create edges (from original Rand_Esu maingraph.cpp)
        // create edge id from u and v (u < v)
        edge e=0;
        if(fromIndex<toIndex){
            e = new_edge(fromIndex, toIndex);
            if(directed) edges[e]=DIR_U_T_V;
            else edges[e]=UNDIR_U_V;
        }
        else{ // toIndex<fromIndex
            e=new_edge(toIndex, fromIndex);
            if(directed) edges[e]=DIR_V_T_U;
            else edges[e]=UNDIR_U_V;            
        }



    }
    name2Index = nameToIndex;
}


    
 // get index of a node given the node's name
    // create an entry if it does not exist
vertex Graph::getOrCreateIndex(string nodeName, unordered_map<string,vertex>& nameToIndex){
    
    if(nameToIndex.count(nodeName)<1){ // if the key does not exists      
        vertex index = (vertex) adjacencyLists.size();
        nameToIndex[nodeName]=index;
         adjacencyLists.push_back(unordered_set<vertex>());     
  //      if(directed) dir_adjacencyLists.push_back(unordered_set<vertex>());
        
    }
    
    return nameToIndex[nodeName];
    
  }


/* print out graph: different from Java print version
 vertices: list of vertices (as <original, index>) 
*/

ostream& operator<< (ostream& out, const Graph& graph){
  
    unordered_map<string, vertex> vertexMap = graph.name2Index;

   
    out<<"Vertices: ";
    for (auto it : vertexMap) 
        out << "< " << it.first << ":" << it.second<<"> ";
    cout<<endl;
    
    
    out<<endl<<"Edges: "<<endl;
        for (auto ed:graph.edges){
            edge code = ed.first;
            edgetype type = ed.second;
            vertex u = edge_get_u(code);
            vertex v = edge_get_v(code);
            out<<"<";
            
            if (type == DIR_U_T_V) out<<u<<"->"<<v;
            else if (type == DIR_V_T_U) out<<v<<"->"<<u;
            else if (type == UNDIR_U_V) out<<u<<"--"<<v;
            out<<"> ";
        
    }
    out<<endl;
    
    int edgec=graph.edges.size();
       
    
     out<<"Directed?="<<graph.directed<<", |V| = "<<graph.adjacencyLists.size()<<": |E| = "<<edgec<<endl;
     
    return out;
            
}

ostream& operator<< (ostream& out, Graph::Edge& edge){
    out<<"["<<edge.nodeA<<","<<edge.nodeB<<"]"<<endl;
    return out;
}


Graph::Edge::Edge(){
    throw invalid_argument("Assertion Error");
    
}



Graph::Edge::Edge(vertex nodeA, vertex nodeB){
    this->nodeA = nodeA;
    this->nodeB = nodeB;    
}

bool Graph::Edge::equals(Graph::Edge& edge, bool dir){
    
    bool result;
    if (dir)
        result = ((edge.nodeA==this->nodeA)&&(edge.nodeB==this->nodeB));
    else
        result = ((edge.nodeA==this->nodeA)&&(edge.nodeB==this->nodeB))||((edge.nodeA==this->nodeB)&&(edge.nodeB==this->nodeA));
    return result;
    
}
