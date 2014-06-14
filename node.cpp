#include "node.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>

void Node::insert(int value){
	if (this->value == value){
		this->qty++;
	}else if (this->value > value) {
		if (this->left){
			this->left->insert(value);
		}else{
			this->left = new Node(value);
		}
	}else if (this->value < value){
		if (this->right){
			this->right->insert(value);
		}else{
			this->right = new Node(value);
		}
	}	
}

std::string Node::describe(bool showdepth){
	std::stringstream ss;
	ss << "Value: " << std::setw(3) << getvalue();
	ss << ", qty: " << std::setw(3) << getqty();
	if (showdepth){ 
		ss << ", depth: " << std::setw(2) << getdepth(); 
		ss << ", column: " << std::setw(2) << getcolumn();
	}
	
	return std::string(ss.str());
}

void Node::visit(Order ord){
	if (ord == Order::PREORDER)
		std::cout << describe() << std::endl;
	if (this->left)
		this->left->visit(ord);
	if (ord == Order::INORDER)
		std::cout << describe() << std::endl;
	if (this->right)
		this->right->visit(ord);
	if (ord == Order::POSTORDER)
		std::cout << describe() << std::endl;
}



