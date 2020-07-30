#include "Node.hpp"

Node::~Node()
{
	if (left_ != nullptr) delete left_;
	if (right_ != nullptr) delete right_;
}