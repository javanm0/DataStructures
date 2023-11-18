// Digraph.cpp -- directed graph class
// c. 2017 T. O'Neil

#include "Digraph.hpp"

const int INF = std::numeric_limits<int>::max();

// Returns the number of vertices in the graph
unsigned int Digraph::noVertices()
{
    return numberOfVertices;
}

// Returns the number of edges in the graph
unsigned int Digraph::noEdges()
{
    return numberOfEdges;
}

// Resets all edges to 0
void Digraph::resetEdges()
{
    for (int i = 0; i < distMatrix.size(); i++) // Each row
    {
        for (int j = 0; j < distMatrix.size(); j++) // Each element in row
        {
            distMatrix[i][j] = INF; // Resets to 0
        }
    }
}

// Add an undirected edge to the graph from source to dest with weight wt
void Digraph::addEdge(int source, int dest, int wt)
{
    distMatrix[source][dest] = wt; // Add edge from source to dest
    distMatrix[dest][source] = wt; // Add edge from dest to source
}

// Delete the edge from source to dest
void Digraph::delEdge(int source, int dest)
{
    distMatrix[source][dest] = INF; // Set edge from source to dest to max
    distMatrix[dest][source] = INF; // Set edge from dest to source to max 
}

// Returns whether there is an edge from source to dest
int Digraph::isEdge(int source, int dest)
{
    if (distMatrix[source][dest] != INF) // If edge exists
    {
        return distMatrix[source][dest]; // Return weight
    }
    else // If edge does not exist
    {
        return 0;
    }
}

// Use Dijkstra's algorithm to find the shortest path from source to dest
int Digraph::dijkstra(int source, int dest)
{
    std::vector<int> distance(numberOfVertices, INF); // Vector contains distances from source to each vertex 
    distance[source] = 0;

    for (int i = 0; i < numberOfVertices; i++) 
    {
        int minDistance = 0;
        for (int j = 0; j < numberOfVertices; j++)
        {
            if ((vertex[j]->getStatus() == NOT_VISITED) && (distance[j] < distance[minDistance]))
            {
                minDistance = j; // Set vertexIndex to index of vertex with minimum distance
            }
        }

        vertex[minDistance]->setStatus(VISITED); // Set vertex to visited

        // If vertexIndex is not set or if destination vertex is reached
        for (int i = 0; i < numberOfVertices; i++)
        {
            // Find a distance smaller than current distance[i]  
            if (((distMatrix[minDistance][i] != INF)) && (distance[minDistance] + distMatrix[minDistance][i] < distance[i])) // If edge exists and distance is shorter than current distance, a better route is found
            {
                distance[i] = distance[minDistance] + distMatrix[minDistance][i]; // Update distance if greater is found
            }
        }
    }

    // Reset all vertices to not visited
    for (int i = 0; i < numberOfVertices; i++)
    {
        vertex[i]->setStatus(NOT_VISITED);
    }

    // Returns distance to destination vertex if it is reached
    return distance[dest];
}

