#include "node.hpp"
#include <sstream>
#include <iomanip>
#include <iostream>
#include <memory>  // smart pointers - using shared_ptr 
#include <deque>


#define COFSET 2


void Node::insert(int value){
	if (this->value == value){
		this->qty++;
	}else if (this->value > value) {
		if (this->left){
			this->left->insert(value);
		}else{
			this->left = std::shared_ptr<Node> ( new Node(value) );
		}
	}else if (this->value < value){
		if (this->right){
			this->right->insert(value);
		}else{
			this->right = std::shared_ptr<Node> ( new Node(value) );
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

int Node::visit(Order ord){
	int total = 0;
	if (ord == Order::BREADTH){
		calcDepth();
		std::deque< std::shared_ptr<Node> > q;
		q.push_back( shared_from_this() );
		while (!q.empty()){
			std::shared_ptr<Node> anode = q.front();
			q.pop_front();
			std::cout <<  anode->describe(true) << std::endl;
			total += anode->getqty();
			if (anode->left)
				q.push_back(anode->left);
			if (anode->right)
				q.push_back(anode->right);

		}
		return total;		
		
	}
	if (ord == Order::PREORDER){
		std::cout << describe() << std::endl;
	}
	if (this->left){
		total += this->left->visit(ord);
	}
	if (ord == Order::INORDER){
		std::cout << describe() << std::endl;
	}
	if (this->right){
		total += this->right->visit(ord);
	}
	if (ord == Order::POSTORDER){
		std::cout << describe() << std::endl;
	}
	total += this->getqty();
	return total;
}


void Node::calcDepth(int depth, int column){
	this->depth = depth;
	this->column = column;
	if (this->left){
		this->left->calcDepth(depth + 1, column - COFSET);
	}
	if (this->right){
		this->right->calcDepth(depth + 1, column + COFSET);
	}


}

