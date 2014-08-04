#include <iostream>
#include <functional>
#include <string>

/* mutable capture by value : at time of declaration!  If made mutable, local copy
	carries over from call to call retaining local value.  It doesnt matter
	what is done to non local copy of variable outside of lambda calls. see
	what happens to varible b.

	non mutable capture by value : always the value at time of declaration, not
	invocation

	capture by reference, value inside and outside lambda are in synch at all times
	see var a
*/


int main(int argc,char** argv){


int a = 3;
int b = 4;

std::function<int (int)> accum = [&,b](int x)mutable -> int{
	std::cout << "accum sees a = " << a << ", b = " << b << std::endl;
	a=a+3;
	b=b+3;
	return a + b + x;
};
std::cout << "line: " << __LINE__ << " ";
std::cout << "a = " << a;		// a=3
std::cout << " ,b  = " << b;	// b=4
std::cout << std::endl;

std::cout << accum(5) <<  " at " << __LINE__ << std::endl; //  6+7+5=18 <- here local b=7
std::cout << "line: " << __LINE__ << " ";
std::cout << "a = " << a;		//a=6 perm changed since captured by ref
std::cout << " ,b  = " << b;    //b=4 since capture by value, mutables is local changed only
std::cout << std::endl;
a=11;
b=12;
std::cout << "line: " << __LINE__ << " ";
std::cout << "a = " << a;		//a=11
std::cout << " ,b  = " << b;	//b=12
std::cout << std::endl;

std::cout << accum(5) <<  " at " << __LINE__ << std::endl; // (11+3) + (7+3) + 5  = 29 <- local b = 10
std::cout << "line: " << __LINE__ << " ";
std::cout << "a = " << a;	// a=14  lambda takes a at exec, adds 3 : a by ref= perm change
std::cout << " ,b  = " << b; //b=12, no change since by value.
std::cout << std::endl;


std::cout << accum(5) <<  " at " << __LINE__ << std::endl; // (11+3+3) + (7+3+3) + 5  = 29
std::cout << "line: " << __LINE__ << " ";
std::cout << "a = " << a;	// a=14  lambda takes a at exec, adds 3 : a by ref= perm change
std::cout << " ,b  = " << b; //b=12, no change since by value.
std::cout << std::endl;
}


