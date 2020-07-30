//Name: Dylan Ford
//Date: Dec 10, 2019
//Description: Contains root node attribute for top of binary tree and constructor/destructor declarations

#pragma once
#include "Node.hpp"
#include "Patient.hpp"

class BinaryTree {
public:
	Node* root_;

	BinaryTree();
	~BinaryTree();
};