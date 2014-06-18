#include <iostream>

#define INITIALSIZE 200


using namespace std;

class IntArray;

class Itr{
	// must impl operators != for comparison during iteration
	//					   ++ to enable iteration to next
	//                     *  to return item in collection.
	public:
	Itr ( int* pos )   
		: _pos( pos )
		{}

	bool
	operator!= (const Itr& other) const
	{
		return _pos != other._pos;  // compare address of element
	}

	int operator * () const;

	const Itr& operator++ ()  
	{
		++_pos;  				// increment address of element
		return *this;
	}

	private:
	int* _pos;
	
};
	
class IntArray{
	public:
	IntArray():size(0) {}
	int get (int col) const
	{
		return _data[ col ];
	}
	// creates Itr objects representing begin/end points of collection
	Itr begin () 
	{
		return Itr( &(_data[0]) );
	}
	Itr end () 
	{
		return Itr( &(_data[size]) );
	}
	void set ( int val )
	{
		_data[ size ] = val;
		size++;
	}
	
	private:
	int size ;
	int _data [INITIALSIZE];
};

int 
Itr::operator* () const
{
	return ( *_pos );   // return value of stored item. (int)
}

int main()
{
	IntArray a;
	for (int i = 0; i<100; i++ )
	{
		a.set( i );
	}
	for (auto i : a )
	{
		cout << i << endl;
	}
}



/* 
const notes : applies to left, only if nothing left, apply right
	const int x = 2;  unchanging variables, like #define
	
	const int* x;   //variable ptr to constant      
	int const* x;   //same as above

	int * const x;	//constant pointer to variable - fixed memory location, var content

	int const * const x; //const ptr to constant 

	const char* getstr();   //return a constant string (unalterable)
	void dostuff(largetype const &parm);  //pass a ref for speed/memory - no change allowed
  
    class aclasss
	{ void method1() const;  // bans method1 from altering any members
	  int var; }            

	const int * const method(const int * const &) const;
	int const * const method(int const * const &) const;
		//return a const ptr to const
		//pass in a ref to a const ptr to const int


*/
