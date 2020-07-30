//Name: Dylan Ford
//Date: Dec 10, 2019
//Description: Contains attributes, constructors and a destructor for a node to make a binary tree
#pragma once

enum condition { unknown, uCellSize, bNuclei, cThick, bChrom, mAdhesion, uCellShape, diagnosis };

class Node {
public:
	Node* left_;
	Node* right_;
	int data_;
	int condition_ = unknown;

	//Desc: 1 arg constructor
	//Parms: n/a
	//Return: n/a
	Node(int val) : data_(val), left_(nullptr), right_(nullptr) {}

	//Desc: 2 arg constructor
	//Parms: n/a
	//Return: n/a
	Node(int val, int condition) : data_(val), left_(nullptr), right_(nullptr), condition_(condition) {}

	//Desc: deconstructor
	//Parms: n/a
	//Return: n/a
	~Node() { delete left_; delete right_; }
};