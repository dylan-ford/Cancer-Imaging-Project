//Name: Dylan Ford
//Date: Dec 10, 2019
//Description: Includes methods for construction and destruction of a binary tree

#include "BinaryTree.hpp"

//Desc: constructor
//Parms: n/a
//Return: n/a
BinaryTree::BinaryTree() {
	root_ = new Node(2, uCellSize);

	//left side
	root_->left_ = new Node(3, bNuclei);
	root_->left_->left_ = new Node(2); //benign
	root_->left_->right_ = new Node(3, cThick);
	root_->left_->right_->left_ = new Node(2); //benign	
	root_->left_->right_->right_ = new Node(2, bChrom);
	root_->left_->right_->right_->left_ = new Node(3, mAdhesion);
	root_->left_->right_->right_->left_->left_ = new Node(4); //malignant
	root_->left_->right_->right_->left_->right_ = new Node(2); //benign
	root_->left_->right_->right_->right_ = new Node(4); //malignant

	//right side
	root_->right_ = new Node(2, uCellShape);
	root_->right_->left_ = new Node(5, cThick);
	root_->right_->left_->left_ = new Node(2); //benign
	root_->right_->left_->right_ = new Node(4); //malignant
	root_->right_->right_ = new Node(4, uCellSize);
	root_->right_->right_->left_ = new Node(2, bNuclei);
	root_->right_->right_->left_->left_ = new Node(3, mAdhesion);
	root_->right_->right_->left_->left_->left_ = new Node(2); //benign 
	root_->right_->right_->left_->left_->right_ = new Node(4); //malignant
	root_->right_->right_->left_->right_ = new Node(6, cThick);
	root_->right_->right_->left_->right_->left_ = new Node(3, uCellSize);
	root_->right_->right_->left_->right_->left_->left_ = new Node(4); //malignant
	root_->right_->right_->left_->right_->left_->right_ = new Node(5, mAdhesion);
	root_->right_->right_->left_->right_->left_->right_->left_ = new Node(2); //benign
	root_->right_->right_->left_->right_->left_->right_->right_ = new Node(4); //malignant
	root_->right_->right_->left_->right_->right_ = new Node(4); //malignant
	root_->right_->right_->right_ = new Node(4); //malignant
}

//Desc: deconstructor
//Parms: n/a
//Return: n/a
BinaryTree::~BinaryTree() {
	delete root_;
}