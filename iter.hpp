#include "node.hpp"
#include <memory>

class Iter{
public:
	Iter ( const shared_ptr<Node> p_vec, int pos )
		: _pos( pos )
		, _p_vec( p_vec )
	{}

	bool
	operator!=( const Iter&  other ) const
	{
		return _pos != other._pos;
	}

	int operator* () const;

	const Iter& operator++ ()
	{
		++_pos;
		return *this;
	}

	private:
	int _pos;
	const shared_ptr<Node> _p_vec;
};



