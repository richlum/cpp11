#include <iostream>
#include <functional>



int main(int argc, char** argv) {

int x = 1;
int y = 2;
int z = 3;

std::function<int(int)>  tester = [=](int a)mutable -> int {
	x=x+x;
	std::cout << "x = " << x << std::endl;
	return (x+y+z)*a;
};

z = 9;
for (int i=0;i<4;i++) {
	std::cout << tester(i) << std::endl;
}



}


