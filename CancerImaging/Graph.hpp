//Name: Dylan Ford
//Date: Dec 10, 2019
//Description: contains attributes and methods to create a graph
#pragma once
#include "AdjList.hpp"
#include <string>

class Graph {
public:
	int numVertices_;
	AdjList* adjList_;
	Graph(int);
	~Graph();
	void addEdge(int src, int dest, int weight);
	void incrementEdge(int src, int dest);
	void printGraph();
	std::string toString(int vertice);
};