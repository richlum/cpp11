#include <functional>
#include <iostream>


int main(int argc, char** argv){

	int total = 0;
	// capture total by ref any other var by value
	std::function<int(int)> accum = [&total](int x){
		total += x;
		return x;
	};

	for (int i=0;i<10;i++){
		std::cout << "inserting value " << accum(i) << ", total = " << total << std::endl;
	}

	std::cout << "==========" << std::endl;
	int valtotal = 0;
	std::function<int(int)> accumByValue = [valtotal](int x) mutable -> int{
		valtotal+= x;
		std::cout << "(valtotal = " << valtotal << ")  ";
		return x;
	};
	
	for (int i=0;i<10;i++){
		std::cout << "inserting value " << accumByValue(i);
		std::cout << std::endl;
	}
	std::cout << "valtotal outside of lambda function = " << valtotal << std::endl;

}
