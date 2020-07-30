//Name: Dylan Ford
//Date: Dec 10, 2019
//Description: implementation of constructor/destructor and graph methods
#include "Graph.hpp"
#include <iostream>

//Desc: 1 arg constructor
//Parms: n/a
//Return: n/a
Graph::Graph(int size) : numVertices_(size)
{
	adjList_ = new AdjList[size];

	//initilizing the adjacency list
	for (size_t i = 0; i < size; i++)
	{
		adjList_[i].head_ = nullptr;
	}

	//create empty adjacency matrix
	for (int i = numVertices_ - 1; i >= 0; i--)
	{
		for (int j = i; j >= 0; j--)
		{
			this->addEdge(i, j, 0);
		}
	}
}

//Desc: deconstructor
//Parms: n/a
//Return: n/a
Graph::~Graph() {
	//call to delete adjList
	for (size_t i = 0; i < 8; i++)
	{
		delete adjList_[i].head_;
	}
	
	delete adjList_;
}

//Desc: adds a graphnode representing an edge object between vertices of a graph
//Parms: 3 ints: source vertice, destination vertice, edge weight
//Return: n/a
void Graph::addEdge(int src, int dest, int weight) {
	GraphNode* newNode = new GraphNode(dest, weight);
	newNode->next_ = adjList_[src].head_;
	adjList_[src].head_ = newNode;

	if (src != dest)
	{
		//add the reverse to complete adjacency matrix
		newNode = new GraphNode(src, weight);
		newNode->next_ = adjList_[dest].head_;
		adjList_[dest].head_ = newNode;
	}	
}

//Desc: increments the weight of an edge object
//Parms: source node and destination node
//Return: n/a
void Graph::incrementEdge(int src, int dest) {
	GraphNode* current = adjList_[src].head_;
	while (current != nullptr)
	{
		if (current->dest_ == dest)
		{
			current->weight_++;
		}
		current = current->next_;
	}

	current = adjList_[dest].head_;
	while (current != nullptr)
	{
		if (current->dest_ == src)
		{
			current->weight_++;
		}
		current = current->next_;
	}
}

//Desc: prints the contents of the graph
//Parms: n/a
//Return: n/a
void Graph::printGraph()
{
	std::printf("%18s", "");
	for (size_t i = 0; i < numVertices_; i++)
	{
		std::printf("%18s", toString(i).c_str());
	}

	std::cout << std::endl;

	// initialize the AdjList
	for (size_t i = 0; i < numVertices_; i++)
	{		
		std::printf("%18s", toString(i).c_str());

		GraphNode* ptr = adjList_[i].head_;
		while (ptr != nullptr)
		{
			std::printf("%18d", ptr->weight_);
			ptr = ptr->next_;
		}
		std::cout << std::endl;
	}
}

//Desc: takes the number of the vertice and returns a string of what the vertice represents
//Parms: integer representing the number of the vertice
//Return: string
std::string Graph::toString(int vertice) {
	switch (vertice)
	{
	case 0: 
		return "Gender";
	case 1:
		return "Age";
	case 2:
		return "Genetic Factor";
	case 3:
		return "Family History";
	case 4:
		return "Overweight";
	case 5:
		return "Alcoholic";
	case 6:
		return "Smoking";
	case 7:
		return "HRT";			
	default:
		return "Error";
	}
}