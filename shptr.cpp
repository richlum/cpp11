#include <iostream>
#include <vector>
#include <string>
#include <memory>  //shared_ptr

class Shape {
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

typedef  std::vector<std::shared_ptr<Shape*>> shapevector;

//std::vector<std::shared_ptr<Shape*>>* populate(int qty){
shapevector* populate(int qty){
	shapevector* shapes = new std::vector<std::shared_ptr<Shape*>>(); // = new std::vector<Shape*>();
	//std::shared_ptr<Shape> s1 = std::make_shared<Shape>( Shape (1,1) );
	for (int i = 0;i<qty;i++){
		shapes->push_back( std::make_shared<Shape*>( new Shape (i,i+1) ));
	}
	return shapes;
}

shapevector* move(int x , int y, shapevector* sv) {
	for (std::shared_ptr<Shape*> s : *sv ) {
		(*s)->setPos( (*s)->getX() + x, (*s)->getY() + y);
	}
	return sv;

}

void empty (shapevector* sv){
	for (std::shared_ptr<Shape*> s : *sv) {
		s.reset();  // note reset is a shared_ptr method  
	}
		
}
int main(int argc, char** argv) {

	shapevector* shapes = populate(5);
	shapes = move(3,2,shapes); 
	int i = 0;
	for (auto s : *shapes) {
		std::cout << ++i << " : " << (*s)->whatami() << std::endl;
	}
	
	//std::cout << s1->whatami() << std::endl;
}
	