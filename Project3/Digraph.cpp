// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"

// Returns the number of vertices in the graph
unsigned int Digraph::noVertices()
{
    return distMatrix.size();
}

// Returns the number of edges in the graph
unsigned int Digraph::noEdges()
{
    unsigned int countEdge = 0; // Counts the number of edges

    for (int i = 0; i < distMatrix.size(); i++) // Each row
    {
        for (int j = 0; j < distMatrix.size(); j++) // Each element in row
        {
            if (distMatrix[i][j] != 0) // Is edge when not 0
            {
                countEdge++; // Adds to countEdge
            }
        }
    }

    return countEdge / 2; // Returns half because of symmetry
}

// Resets all edges to 0
void Digraph::resetEdges()
{
    for (int i = 0; i < distMatrix.size(); i++) // Each row
    {
        for (int j = 0; j < distMatrix.size(); j++) // Each element in row
        {
            distMatrix[i][j] = 0; // Resets to 0
        }
    }
}

// Add an undirected edge to the graph from source to dest with weight wt
void Digraph::addEdge(int source, int dest, int wt)
{
    distMatrix[source][dest] = wt; // Add edge from source to dest
    distMatrix[dest][source] = wt; // Add edge from dest to source
}

void Digraph::delEdge(int source, int dest)
{
}

int Digraph::isEdge(int source, int dest)
{
    return 0;
}

int Digraph::dijkstra(int source, int dest)
{
    return 0;
}