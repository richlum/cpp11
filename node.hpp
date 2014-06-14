#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <string>
#include <cstdint>

enum class Order  { PREORDER, INORDER, POSTORDER };




class Node{
	int value;
	int qty;
	Node* left;
	Node* right;
	int depth;
	int column;
	
public:
	Node(int v):value(v),qty(1),left(nullptr),right(nullptr),
				depth(0),column(0) {};
	void insert(int value);
	void visit(Order ord=Order::INORDER);
	int getvalue(){
		return value;
	}
	int getqty(){
		return qty;
	}
	int getdepth(){
		return depth;
	}
	int getcolumn(){
		return column;
	}
	
private:
	std::string describe(bool showdepth=false);
	void calcDepth(int depth, int column);

};
#endif
