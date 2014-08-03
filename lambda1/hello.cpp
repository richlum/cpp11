#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>

std::function<int (int,int)> mypow = [](int a,int b){ 
	if (b == 0) return 1;
	else return ( a * mypow(a,b-1) );
	};


int main(int argc, char** argv){
	
	std::cout << "Hello World" << std::endl;
	int power = 2;
	if (argc == 2) {
		power = atoi(argv[1]);
	}

	std::cout << " 4 to the power of"  
				<< power << " = " << mypow(4,power) << std::endl;	
}
