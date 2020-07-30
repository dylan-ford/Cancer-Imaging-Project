#pragma once
#include "Node.hpp"
#include "RiskFactor.hpp"

class Patient {
public:
	unsigned long long patientId_, clump_, cellSize_, cellShape_, mAdhesion_, seCellSize_, bareNuclei_, chromatin_, nucleoli_, mitosis_, diagnosis_;
	RiskFactor risk_factor;

	//Desc: determines traversal path down binary tree and assigns benign or malignant diagnosis when at a leaf
	//Parms: node
	//Return: n/a
	void traverse(Node* node) {
		if (node->condition_ == uCellSize) //cellsize
		{
			if (this->cellSize_ <= node->data_)
			{
				traverse(node->left_);
			}
			else
				traverse(node->right_);
		}
		else if (node->condition_ == bNuclei) //bare nuclei
		{
			if (this->bareNuclei_ <= node->data_)
			{
				traverse(node->left_);
			}
			else
				traverse(node->right_);
		}
		else if (node->condition_ == cThick) //clump thickness
		{
			if (this->clump_ <= node->data_)
			{
				traverse(node->left_);
			}
			else
				traverse(node->right_);
		}
		else if (node->condition_ == bChrom) //base chromatin
		{
			if (this->chromatin_ <= node->data_)
			{
				traverse(node->left_);
			}
			else
				traverse(node->right_);
		}
		else if (node->condition_ == mAdhesion) //marginal adhesion
		{
			if (this->mAdhesion_ <= node->data_)
			{
				traverse(node->left_);
			}
			else
				traverse(node->right_);
		}
		else if (node->condition_ == uCellShape) //cell shape
		{
			if (this->cellShape_ <= node->data_)
			{
				traverse(node->left_);
			}
			else
				traverse(node->right_);
		}
		else
			this->diagnosis_ = node->data_;	//if at leaf, set patient diagnosis to the node data
	}
};
