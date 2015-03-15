#include<functional>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

template<typename T>
void filler(T* begin, T* end, function<T(T)> f ) {

	generate(begin,end, f);
}


int main (int argc, char** argv) {
	
	vector<int> v(12,0);
	
	int init = 3;
	int x = 4;
//	function<int(int)> fib = [=](int x) mutable -> int {
//		init += x;
//		return init;
//	}(4);
	
//	filler<int*,int*,function<int(int)>(v.begin(), v.end(), fib);
	generate(v.begin(), v.end(), [&]( ) {
		init += x;
		return init;
	}   );
	
	for ( auto i : v ) {
		std::cout << i << std::endl;
	}

	for_each(v.begin(), v.end(), [](int& x) { 
		std::cout << "foreach " << x << std::endl;
		x += -2;;
	} );

	for ( auto i : v ) {
		std::cout << i << std::endl;
	}

}

