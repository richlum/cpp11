#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>

int main(int argc, char** argv){
	int base  = 4;	
	int power = 2;
	// note that captures base as 2 here regardless of
	// later value.
	std::function<int (int)> mypow = [&](int power){ 
		if (power == 0) return 1;
		else return ( base * mypow(power-1) );
		};

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
				<< power << " = " << mypow(power) << std::endl;	
}
