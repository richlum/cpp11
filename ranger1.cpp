#include <iostream>

using namespace std;

class IntArray;

class Itr{
	public:
	Itr (const IntArray* p_vec, int pos)
		: _pos( pos )
		, _p_vec( p_vec )
		{}

	bool
	operator!= (const Itr& other) const
	{
		return _pos != other._pos;
	}

	int operator * () const;

	const Itr& operator++ ()
	{
		++_pos;
		return *this;
	}

	private:
	int _pos;
	const IntArray *_p_vec;
	
};
	
class IntArray{
	public:
	IntArray() {}
	int get (int col) const
	{
		return _data[ col ];
	}
	Itr begin () const
	{
		return Itr( this, 0 );
	}
	Itr end () const
	{
		return Itr( this,100 );
	}
	void set (int index, int val)
	{
		_data[ index ] = val;
	}
	
	private:
	int _data [100];
};

int 
Itr::operator* () const
{
	return _p_vec->get( _pos );
}

int main()
{
	IntArray a;
	for (int i = 0; i<100; i++ )
	{
		a.set( i,i );
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
