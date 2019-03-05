/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandomGraphGenerator.cpp
 * Author: Wooyoung
 * 
 * Created on November 2, 2017, 1:23 PM
 */

#include "RandomGraphGenerator.h"


RandomGraphGenerator::RandomGraphGenerator() {
}



RandomGraphGenerator::~RandomGraphGenerator() {
}

int nextInt2(int min, int max){
    return rand() % (max - min + 1) + min;
}


Graph RandomGraphGenerator:: generate(Graph& inputGraph){
    vector<int> degreeSeq = getDegreeSequenceVector(inputGraph);
   
    
    bool directed = inputGraph.isDirected();
    Graph randomGraph(directed);
    
    // generate randomized list of vertices
    // the vertexList is a set where each node is represented by a number
    // of elements equal to that vertex's degree
    
    vector <int> vertexList;
    for (int vertex = 0; vertex<inputGraph.getSize();++vertex){
        randomGraph.addVertex();
        for (int degree=0; degree<degreeSeq[vertex];++degree)
            vertexList.push_back(vertex);        
    }
    
    random_shuffle(vertexList.begin(), vertexList.end());
    
    // create edges
    int u,v;
    for (int c=0; vertexList.size()>1;++c){
        u = nextInt2(0, vertexList.size()-1);
        // make sure v != u
        v = nextInt2(0, vertexList.size()-1);
        while (v==u){
             v = nextInt2(0, vertexList.size()-1);
        }
        //swap if u>v
        if (u>v){
            int temp = u;
            u=v;
            v=temp;
        }
        
         
        int edgeVertexV = vertexList[v];
        int edgeVertexU = vertexList[u];    
       
      
        vertexList.erase(vertexList.begin()+ v );
        vertexList.erase(vertexList.begin() +u);
        
         if (edgeVertexV == edgeVertexU) continue; // avoid self-edge
 
        
        randomGraph.addEdge(edgeVertexU, edgeVertexV);
        
    }
    return randomGraph;
    
    
    
}

Graph RandomGraphGenerator::generate(Graph& inputGraph, vector <int> probs){
    vector<int> degreeSeq = getDegreeSequenceVector(inputGraph);
    bool directed = inputGraph.isDirected();
    Graph randomGraph(directed);
    
    // generate randomized list of vertices
    // the vertexList is a set where each node is represented by a number
    // of elements equal to that vertex's degree
    
    vector <int> vertexList;
    for (int vertex = 0; vertex<inputGraph.getSize();++vertex){
        randomGraph.addVertex();
        for (int degree=0; degree<degreeSeq[vertex];++degree)
            vertexList.push_back(vertex);        
    }
    random_shuffle(vertexList.begin(), vertexList.end());
    
    // create edges
    int u,v;
    vector<int>::iterator it=probs.begin(); 
    for (int c=0; vertexList.size()>1;++c){
        u = *(it++); 
        // make sure v != u
       v=*(it++);
        while (v==u){
             v=*(it++);
        }
        //swap if u>v
        if (u>v){
            int temp = u;
            u=v;
            v=temp;
        }
        int edgeVertexV = vertexList[v];
        int edgeVertexU = vertexList[u];
       vertexList.erase(vertexList.begin()+ v);
        vertexList.erase(vertexList.begin() +u);
         if (edgeVertexV == edgeVertexU) continue; // avoid self-edge
        randomGraph.addEdge(edgeVertexU, edgeVertexV);        
    }
    return randomGraph; 
    
    
    
 
    
}

/**
 * Generates a degree sequence vector for a given Graph
 * @param inputGraph the Graph from which to derive the degree sequence
 * vector
 * @return a List representing the degree sequence vector
 */

vector<int> RandomGraphGenerator::getDegreeSequenceVector(Graph& inputGraph) {
    vector <int> degreeSequenceVector;
    for (int currentVertex = 0; currentVertex < inputGraph.getSize(); ++currentVertex) {
        int degree = inputGraph.getAdjacencyList(currentVertex).size();
        degreeSequenceVector.push_back(degree);
    }
    return degreeSequenceVector;
}
