//Name: Dylan Ford
//Date: Dec 10, 2019
//Description: attributes and methods of a node for a graph's adjacency matrix
#pragma once

enum Vertice { Gender, Age, GeneFact, FamHist, Overweight, Alcoholic, Smoking, HRT };

class GraphNode {
public:
	int dest_;
	int weight_;
	GraphNode* next_;

	//Desc: 2 arg constructor
	//Parms: n/a
	//Return: n/a
	GraphNode(int dest, int weight) : dest_(dest), weight_(weight), next_(nullptr) {}

	//Desc: deconstructor
	//Parms: n/a
	//Return: n/a
	~GraphNode() { delete next_; }
};