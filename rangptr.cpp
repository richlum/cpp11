#include <iostream>
#include <stdexcept>
#include <cstdio>

/**  
	@brief enable use of for each looping with our own deque class
	
	Implement 5 required methods as part of collection to enable use 
	of c++ 11 for each looping construct.  In this variant we implement
	a deque using doubly linked nodes and use it as a LIFO stack, pushing
	and popping from the back.  Itr class contains the three required 
	operators  (comparator, increment, dereference) :(!=, ++, *)
	IntDeq implements the begin and end functions required.
	
	\author Richard Lum
	\version 1.00
	\date 20140617
	
	\bug for each loop does not show all entries. Off by one.
*/

using namespace std;

class Deq;

/** Double linked Nodes to hold integer data */
class Node{
	/** Deq has access to prev/next members */
	friend class Deq;
	int value;
	Node* prev;
	Node* next;
	
	public:
	/** construct a node holding given value */
	Node(int value, Node* prev = nullptr, Node* next = nullptr)
		: value(value), prev(prev), next(next)
		{}
	void setprev(Node* p = nullptr){	/** set prev node pointer */
		prev = p;
		}
	void setnext(Node* n = nullptr){	/** set next node pointer */
		next = n;
		}
	Node* getprev(){					/** get prev node pointer */
		return prev;
		}
	Node* getnext(){					/** get next node pointer */
		return next;
		}
	int getvalue(){						/** get value in node */
		return value;
		}
};		

/** Itr class holds operators for Itr object returned by begin and end */
class Itr{
	public:
	Itr (Node* p_vec)
		: _p_vec( p_vec )
		{}

	bool
	operator!= (const Itr& other) const
	{
		return _p_vec != other._p_vec;
	}

	int operator * () const;
	/** for loop calls this operator to traverse  queue */
	const Itr* operator++ ()
	{
		_p_vec = _p_vec->getnext();
		//cout << "incrementor" << std::endl;
		return this;
	}

	private:
	Node* _p_vec;
};

int 
Itr::operator* () const
{
	return _p_vec->getvalue();
}
	
	

/**  Deque collection class to manage double ended queue of Nodes */
class Deq{
	Node* head;
	Node* tail;
	int size;
	public:
	Deq(Node* head=nullptr, Node* tail=nullptr)
		 : head(head), tail(tail), size(0)
		 {
			if (head != nullptr)
				size++;
		 }
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
		if (tail == nullptr){
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
		if (head == nullptr){
			head = anode;
		}
		size++;
	}
	void popfront(){
		if (head == nullptr)
			return;
		Node* n = head;
		head = head->next;
		head->prev = nullptr;
		n->next = nullptr;
		delete n;
		n = nullptr;
		size--;
	}		
	void popback(){
		if (tail == nullptr)
			return;
		Node* n = tail;
		tail = tail->prev;
		tail->next = nullptr;
		n->prev = nullptr;
		delete n;
		n = nullptr;
		size--;
	}
	int getsize(){
		return size;
	}
};

/** Subclass of deque to implement begin and end members for managing queue */
class IntDeq: public Deq{
	public:
	IntDeq() {}
	/** allow 'direct' access by position for testing */
	int get (int col) /**  @param col specifies 0 based count of members in deque */
	{
		if ( (col > getsize()) || (col <= 0) ){
			char errmsg[64];
			sprintf(errmsg,"received %d, max %d",col,getsize());
			throw out_of_range(string(errmsg));
		}	
		int cntr = 1;
		Node* pnode = this->front();
		while( (cntr < col) && (pnode!=nullptr) ){
			pnode = pnode->getnext();
			cntr++;
		}
		if (pnode == nullptr){
			char errmsg[64];
			sprintf(errmsg,"Node not found for %d",col);
			throw std::logic_error(string(errmsg));
		}
			
		return pnode->getvalue();
	}
	/**  Get Itr containing first member of queue */
	Itr begin () 
	{
		return Itr( this->front() );
	}
	/** Get Itr containing last member of queue */
	Itr end () 
	{
		return Itr( this->back() );
	}
	/** add a node to the end of the queue to hold value */
	void set ( int val )  /** @param val is stored in tail of queue */
	{
		this->pushback( val );
	}
	
	private:
	Deq _data;
};





int main()
{
	
		IntDeq a;
		for (int i = 0; i<100; i++ )
		{
			a.set( i );
		}
	try{	
		for (auto i : a )
		{
			cout << i << " : "   <<  a.getsize()   << endl;
		}
		
		int i = 99;
		cout << i << "  " << a.get(i) << std::endl;
		i++;
		cout << i << "  " << a.get(i) << std::endl;
		i++;
		cout << i << "  " << a.get(i) << std::endl;
	}catch ( out_of_range e) {
		cout << e.what();
	}catch ( logic_error e) {
		cout << e.what();
	}catch ( exception e) {
		cout << e.what() << std::endl;
	}
}

