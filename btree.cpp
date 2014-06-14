
#include "node.hpp"
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <time.h>
#include <string>

#define UPB 100

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

	Node* root = new Node(13);
	root->insert(11);
	root->insert(100);
	root->insert(44);
	root->insert(7);

	for (int i=0; i< qty; i++) {
		root->insert(getrand());
	}

	root->visit();



}
