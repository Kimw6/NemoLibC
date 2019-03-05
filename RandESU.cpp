/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RandESU.cpp
 * Author: Wooyoung
 * 
 * Created on October 25, 2017, 10:28 AM
 */

#include "RandESU.h"



/** Determines whether or not to extend based on a given probability, given
        as an integer.
        precondition: 0.0 <= prob <= 1.0
 **/
// return an integer between min and max inclusively

int nextInt(int min, int max) {
    return rand() % (max - min + 1) + min;
}

vertex nextVertex(vertex min, vertex max) {
    return rand() % (max - min + 1) + min;
}

bool RandESU::shouldExtend(const double prob) {


    if (prob == 1.0) {
        return true;
    }

    if (prob == 0.0) {
        return false;
    }

    if (prob > 1.0 || prob < 0.0) {
        throw invalid_argument("RAND-ESU probability outside acceptable range (0.0 to 1.0)");
    }
    // a random number between 0 and 100
    int randNum = nextInt(0, 100);
    return randNum <= (prob * 100.0);
}

/** Returns true if the node index is exclusive to the given subgraph
        (that is, is not already in the subgraph, and is not adjacent to any of
         the nodes in the subgraph)
 **/

bool RandESU::isExclusive(Graph& graph, vertex node, Subgraph& subgraph) {

    for (int i = 0; i < subgraph.getSize(); i++) {
        vertex subgraphNode = subgraph.get(i);
        if (subgraphNode == node) {
            return false;
        }
    }

    for (int i = 0; i < subgraph.getSize(); i++) {
        vertex subgraphNode = subgraph.get(i);

        if (graph.getAdjacencyList(subgraphNode).count(node) > 0) {

            return false;
        }
    }

    return true;

}

/**
 * Enumerates all subgraphSize Subgraphs in the input Graph using the 
 * RAND-ESU algorithm.
 *
 * @param graph           the graph on which to execute RAND-ESU
 * @param subgraphSize    the size of the target Subgraphs
 */

void RandESU::enumerate(Graph& graph, SubgraphEnumerationResult& subgraphs, int subgraphsize, const vector<double> probs) {
    // maintain list of nodes selected so far
    std::vector<vertex> selectedVertices;
    if (probs[0] == 1.0) // select all nodes
        for (int i = 0; i < graph.getSize(); i++)
            selectedVertices.push_back(i);
    else {
        //determine how many nodes should be sampled initially
        int numVerticesToSelect = (int) round(probs[0] * graph.getSize());
        for (int nVSelected = 0; nVSelected < numVerticesToSelect; ++nVSelected) {
            vertex nodeSelected = nextVertex(0, graph.getSize() - 1); // get the node id
            // ensure no duplicates
            //std::find(vector.begin(), vector.end(), item) != vector.end()
            //while (selectedVertices.count(nodeSelected)>0)
            while (std::find(selectedVertices.begin(), selectedVertices.end(), nodeSelected) != selectedVertices.end())
                nodeSelected = nextVertex(0, graph.getSize() - 1);
            selectedVertices.push_back(nodeSelected);
        }
    }
    NautyLink nautylink(subgraphsize, graph.getEdges(), graph.isDirected());

    for (vertex v : selectedVertices) {
        enumerate(graph, subgraphs, subgraphsize, probs, v, nautylink);
    }

}

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
 */
void RandESU::enumerate(Graph& graph, SubgraphEnumerationResult& subgraphs, int subgraphsize, const vector<double> probs, vertex vertexV, NautyLink& nautylink) {
    // create a subgraph with given subgraphsize


    Subgraph subgraph(subgraphsize);


    // create an extends
    unordered_set<vertex> adjacencyList = graph.getAdjacencyList(vertexV);
    vector<vertex> extends;

    unordered_set<vertex>::const_iterator iter = adjacencyList.begin();

    while (iter != adjacencyList.end()) {
        vertex next = *iter;

        //add the vertex to the adjacencyList only if the index is bigger than the vertex
        if (next > vertexV)
            extends.push_back(next);
        iter++;
    }

    subgraph.add(vertexV); // add to the subgraph, the vertex and its corresponding adjacencylist




    //randomly decide whether to extend
    if (shouldExtend(probs.at(1))) {
        extend(graph, subgraph, extends, probs, subgraphs, nautylink);
    }



}

void RandESU::extend(Graph& graph, Subgraph& subgraph, vector<vertex> extension, const vector<double> probs, SubgraphEnumerationResult& subgraphs, NautyLink& nautylink) {

    vertex v = subgraph.root();
    vector<vertex>::const_iterator wIter = extension.begin();
    

    // optimize by not creating next extension if subgraph is
    // 1 node away from completion
    if (subgraph.getSize() == subgraph.getOrder() - 1) {
          while (wIter != extension.end()) {

            //cout << "1. subgraph = " << subgraph << endl;
           // cout << "1. Extension=[";
           // for (vertex v : extension) cout << v << " ";
           // cout << "]" << endl;
            
            vertex w = *wIter++;
             
            
            // cout << "1. w = " << w << endl;             
             
 
            // check the last value in prob list
            if (shouldExtend(probs.at(probs.size() - 1))) {
 
                Subgraph subgraphUnion = subgraph.copy();
                subgraphUnion.add(w);
                subgraphs.add(subgraphUnion, nautylink);
            }
            
        }

    }

     // otherwise create the extention
    while (wIter != extension.end()) {
 //        cout << "2. subgraph=" << subgraph << endl;
 //       cout << "2. Extension=[";
//        for (vertex v : extension) cout << v << " ";
 //       cout << "]" << endl;
         vertex w = *wIter;
        
   //       cout << "2. w = " << w << endl;
        extension.erase(wIter);       
        

   //   cout << "3. After erase Extension=[";
    //    for (vertex v : extension) cout << v << " ";
    //    cout << "]" << endl;

        // next extension contains at least the current extension
        vector<vertex> nextExtension = extension;

        // examine each node 'u' from the set of nodes adjacent to 'w'
        // and add it to the next extension if it is exclusive
        unordered_set<vertex> adjW = graph.getAdjacencyList(w);

        //unordered_set<vertex>::const_iterator uIter = adjW.begin();
        auto uIter = adjW.begin();

        while (uIter != adjW.end()) {
            vertex u = *uIter;
            if (u > v)
                if (isExclusive(graph, u, subgraph)) {
                    nextExtension.push_back(u);
                }
              uIter++;
        }

   //     cout << "2. nextExtension=[";
  //      for (vertex v : nextExtension) cout << v << " ";
  //      cout << "]" << endl;


        // construct a union of w and the existing subgraph

        Subgraph subgraphUnion = subgraph.copy();
        subgraphUnion.add(w);
          // randomly choose whether or not to extend to the next level
        // based on the probability vector provided.

      //  wIter++;

        if (shouldExtend(probs.at(subgraphUnion.getSize() - 1))) {
            extend(graph, subgraphUnion, nextExtension, probs, subgraphs, nautylink);
        }
    }
    //  }

 //   cout << "Returning from source " << subgraph << endl;



}