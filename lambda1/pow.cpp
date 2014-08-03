#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>


// recursive calc of power
std::function<int (int,int)> mypow = [](int a,int b){ 
	if (b == 0) return 1;
	else return ( a * mypow(a,b-1) );
	};


int main(int argc, char** argv){
	int base  = 4;	
	int power = 2;
	if (argc == 2) {
		power = atoi(argv[1]);
	}else if (argc == 3){
		power = atoi(argv[2]);
		base  = atoi(argv[1]);
	}else{
		power = 2;
		base = 4;
	}

	std::cout << base <<  " to the power of "  
				<< power << " = " << mypow(4,power) << std::endl;	
}
