#include<iostream>
#include<string>
#include<iomanip>

template<class T>
void f(T s) {
	std::cout << "template " << s << std::endl;
}
void f(double s) {
	std::cout << "double ";
	std::cout << std::fixed <<  std::setprecision(5);
	std::cout  << s << std::endl;
}

int main (int argc, char** argv) {

	f(5);
	f('c');
	f(3.4);
	f("hello world");
}
