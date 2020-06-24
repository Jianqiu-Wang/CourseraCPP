// Graph class 
// Author: Jianqiu Wang, jw2329[at]cornell[dot]edu
// Date: May 10, 2020
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <iostream>

using namespace std;

class Graph
{
private:
    vector<double> vertices_; // value assocated with nodes
    vector<vector<double>> edges_; // adjacency matrix: value associated with edges, 0 means disconncted

public:
    // constructors and destructor
    Graph(int num_nodes, double density, double min_distance, double max_distance);
    // Graph(): Graph(50, 0.1, 1.0, 10) {}; // default constructor
    ~Graph();

    // member functions
    int V(); // number of vertices
    int E(); // number of edges
    bool IsAdjacent(int x, int y); // tests whether there is an edge from node x to node
    vector<int> GetNeighbors(int x); // lists all nodes y such that there is an edge from x to y

    void AddEdge(int x, int y);                // adds to G the edge from x to y, if it is not there.
    void DeleteEdge(int x, int y);             // removes the edge from x to y, if it is there
    double GetNodeValue(int x);                // returns the value associated with the node x.
    void SetNodeValue(int x, double a);           // sets the value associated with the node x to a.
    double GetEdgeValue(int x, int y);         // returns the value associated to the edge (x,y).
    void SetEdgeValue(int x, int y, double v); // sets the value associated to the edge (x,y) to v.

    void PrintEdgeValue();  // prints edge value in matrix form
};

#endif // GRAPH_H_