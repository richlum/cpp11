#ifndef __NODE_HPP__
#define __NODE_HPP__

#include <string>
#include <cstdint>
#include <memory>  // smart pointers - using shared_ptr 
// strongly typed enum
enum class Order  { PREORDER, INORDER, POSTORDER, BREADTH };



           // for passing of share_ptr for 'this' object
class Node: public std::enable_shared_from_this<Node> {
	int value;
	int qty;
	//Node* left;
	//Node* right;
	std::shared_ptr<Node> left;
	std::shared_ptr<Node> right;
	int depth;
	int column;
	
public:                            //  nullptr is t_nullptr, not int
	Node(int v):value(v),qty(1),left(nullptr),right(nullptr),
				depth(0),column(0) {};
	void insert(int value);
	int visit(Order ord=Order::INORDER);
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
	void calcDepth(int depth=1, int column=0);

};
#endif
