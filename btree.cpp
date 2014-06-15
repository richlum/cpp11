#include "node.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <string>
#include <memory>
#include <iomanip>

#define UPB 10

int getrand(){
	return (rand() % UPB) + 1;
}

int main(int argc, char** argv)
{

	int qty = 25;
	if (argc == 2){
		// g++ 4.8.1 - not supported ??
		// qty = std::stoi(std::string(argv[1]),nullptr,10);
		std::string s = argv[1];
		std::stringstream ss( s );
		ss >> qty;
	}
	
	srand(time(NULL));	

	//Node* root = new Node(13);
	std::shared_ptr<Node> root = std::shared_ptr<Node>( new Node(13) );
	root->insert(11);
	root->insert(100);
	root->insert(44);
	root->insert(7);

	for (int i=0; i< qty; i++) {
		root->insert(getrand());
	}
	
	std::cout <<  std::setw(32) << std::setfill('=') << " INORDER/DEFAULT " ;
	std::cout <<  std::endl ;
	
	std::cout <<  "Total: " << root->visit() << std::endl;

	std::cout <<  std::setw(32) << std::setfill('=') << " PREORDER " ;
	std::cout <<  std::endl ;

	std::cout <<  "Total: " << root->visit(Order::PREORDER) << std::endl;

	std::cout <<  std::setw(32) << std::setfill('=') << " POSTORDER " ;
	std::cout <<  std::endl ;

	std::cout <<  "Total: " << root->visit(Order::POSTORDER) << std::endl;

	std::cout <<  std::setw(32) << std::setfill('=') << " BREADTH " ;
	std::cout <<  std::endl ;

	std::cout <<  "Total: " << root->visit(Order::BREADTH) << std::endl;


}
