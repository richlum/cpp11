#include <iostream>

using namespace std;

class Deq;
class IntDeq;

class Itr{
	public:
	Itr (const IntDeq* p_vec, int pos)
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
	const IntDeq *_p_vec;
	
};
	
class IntDeq{
	public:
	IntDeq() {}
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
	Deq _data;
};

int 
Itr::operator* () const
{
	return _p_vec->get( _pos );
}


class Node{
	Node* prev;
	Node* next;
	int value;
	
	public:
	Node(int value, Node* prev = nullptr, Node* next = nullptr)
		: value(value), prev(prev), next(next)
		{}
	void setprev(Node* p = nullptr){
		prev = p;
		}
	void setnext(Node* n = nullptr){
		next = n;
		}
	Node* getprev(){
		return prev;
		}
	Node* getnext(){
		return next;
		}
};		
	
class Deq{
	Node* head;
	Node* tail;
	int size;
	public:
	Deq(Node* head, Node* tail)
		 : head(head), tail(tail), size(0)
		 {}
	Node* front(){
		return head;
	}
	Node* back(){
		return tail;
	}
	void pushfront(int value){
		Node* anode = new Node(value,nullptr,head);
		if (head){
			head->prev = anode;
		}
		head = anode;
		if (tail = nullptr){
			tail = anode;
		}
		size++;
	}
	void pushback(int value){
		Node* anode = new Node(value,tail,nullptr);
		if (tail){
			tail->next = anode;
		}
		tail = anode;
		if (head = nullptr){
			head = anode;
		}
		size++;
	}
	void popfront(){
		if (front == nullptr)
			return;
		Node* n = front;
		front = front->next;
		front->prev = nullptr;
		n->next = nullptr;
		delete n;
		n = nullptr;
		size--;
	}		
	void popback(){
		if (tail == nullptr)
			return;
		Node* n = back;
		back = back->prev;
		back->next = nullptr;
		n->prev = nullptr;
		delete n;
		n = nullptr;
		size--;
	}	
};


int main()
{
	IntDeq a;
	for (int i = 0; i<100; i++ )
	{
		a.set( i,i );
	}
	for (auto i : a )
	{
		cout << i << endl;
	}
}

