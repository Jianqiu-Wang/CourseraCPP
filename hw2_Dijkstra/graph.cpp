// Graph class 
// Author: Jianqiu Wang, jw2329[at]cornell[dot]edu
// Date: May 11, 2020

#include <random>
#include <iomanip>
#include "graph.hpp"

// Default constructor, graph wit 50 nodes, probabily 0.1, distance [1.0, 10.0]
// Graph::Graph()
// {
// }

// Constructor
Graph::Graph(int num_nodes, double density, double min_distance, double max_distance)
{
    default_random_engine generator;
    uniform_real_distribution<double> connection_distribution(0.0,1.0); // generate connected edge
    uniform_real_distribution<double> edge_distribution(min_distance, max_distance); // generate edge value
    auto connect_rand = bind(connection_distribution, generator);
    auto edge_rand = bind(edge_distribution, generator);

    vector<double> edges_to_node_i;
    for (int i=0; i<num_nodes; i++)
    {
        edges_to_node_i.clear();   
        for (int j=0; j<num_nodes; j++)
        {
            if (connect_rand() < density)
            {
                edges_to_node_i.push_back(edge_rand());
            }
            else
            {
                edges_to_node_i.push_back(0);
            }
        }
        edges_.push_back(edges_to_node_i);
    }    
}

// Destructor
Graph::~Graph()
{
}

// Prints edge value 
void Graph::PrintEdgeValue()
{
    
    for (vector<vector<double>>::iterator it1=edges_.begin(); it1 < edges_.end(); it1++)
    {
        for (vector<double>::iterator it2=it1->begin(); it2 < it1->end(); it2++)
        {
            cout << setw(10) << *it2;
        }
        cout << endl;
    }
    cout << endl;
}