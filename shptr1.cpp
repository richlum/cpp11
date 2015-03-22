#include <iostream>
#include <vector>
#include <string>
#include <memory>  //shared_ptr

using namespace std;

class Shape: public std::enable_shared_from_this<Shape> {
	int xpos,ypos;
public:	
	Shape(int x, int y):xpos(x) , ypos(y) {
		std::cout << "Shape constructor at (" << xpos << "," << ypos << ")." << std::endl;
	
	}
	~Shape(){
		std::cout << "Shape dtor at (" << xpos << "," << ypos << ")." << std::endl;
	}
	int getX(){
		return xpos;
	}
	int getY(){
		return ypos;
	}
	void setPos(int x, int y) {
		xpos = x;
		ypos = y;
	}
	std::string whatami() {
		return "Shape at (" +  tostr(xpos) + "," + tostr(ypos) + ").";	
	}
private:	
	std::string tostr( int num){
		return std::to_string(num);
	}
};

template<typename T>
using sptr = std::shared_ptr<T>;

template<typename T>
using wptr = std::weak_ptr<T>;

template<typename T>
using shvect = std::vector<T>;

using shvectorsp = shvect<sptr<Shape>>;
using shvectorwk = shvect<wptr<Shape>>;

shvectorsp* populate(int qty){
	shvectorsp* shapes = new shvectorsp(); 
	for (int i = 0;i<qty;i++){
		shapes->push_back( std::make_shared<Shape>( i, i+1 ));
	}
	return shapes;
}
// use direct vector of shared_ptr - use count incr by for loop
void dmovexy(int x , int y, shvectorsp* sv) {
	for (auto s : *sv ) {
		s->setPos( s->getX() + x, s->getY() + y);
	}
}
// use shared_from_this -> could be persistent copies if needed
void smovexy(int x, int y, shvectorsp* sv) {
	sptr<Shape> ssp;
	for (auto s : *sv ) {
		ssp = s->shared_from_this();
		if (ssp) {
			ssp->setPos( ssp->getX() + x, ssp->getY() + y );
		}else{
			std::cerr << "unable to retrieve share_ptr" << std::endl;
		}
	}
}
// assuming we have weak_ptr -> get shared_ptr to update	
void wmovexy(int x, int y, shvectorwk* sv) {
	sptr<Shape> shapesptr;
	for (auto s: *sv) {
		shapesptr = s.lock();
		if(shapesptr) {
			shapesptr->setPos( shapesptr->getX() + x, shapesptr->getY() + y );
		} else {
			std::cerr << "unable to get shared from weak_ptr" << std::endl;
		}
	}
}

void empty (shvectorsp* sv){

	for (auto  s : *sv) {
		s.reset();
	}
		
}
void show(shvectorsp* sv) {
	int i = 0;
	for (auto s : *sv) {
		std::cout << ++i << " : " << s->whatami() << std::endl;
	}
}

shvectorwk* getWkShVect (shvectorsp* ssv) {
	shvectorwk* wsv = new shvectorwk();
	for (auto s :  *ssv) {
		wsv->push_back(s->shared_from_this());
	}
	return wsv;
}



int main(int argc, char** argv) {

	shvectorsp* shapes = populate(5);
	dmovexy(3,2,shapes); 
	show (shapes);	
	empty (shapes);
}
