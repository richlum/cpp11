#include <iostream>
#include <string>
#include <functional>
#include <cstdlib>




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

	// recursive calc of power
	std::function<int (int)> mypow = [&](int power){ 
		if (power == 0) return 1;
		else return ( base * mypow(power-1) );
		};

	std::cout << base <<  " to the power of "  
				<< power << " = " << mypow(power) << std::endl;	
	
	double based = 3.21;
	std::function<double (int)> accum = [&](int power) -> double{
		if (power == 0) return 1.0;
		else return ( based * accum(power-1) );
		};

	std::cout << based << " to the power of " 
				<< power << " = " << accum(power) << std::endl;



}
