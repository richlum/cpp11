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
	std::string whatami() {
		return "Shape at (" +  tostr(xpos) + "," + tostr(ypos) + ").";	
	}
private:	
	std::string tostr( int num){
		return std::to_string(num);
	}
};


int main(int argc, char** argv) {
	std::vector<std::shared_ptr<Shape>> shapes; // = new std::vector<Shape*>();
	std::shared_ptr<Shape> s1 = std::make_shared<Shape>( Shape (1,1) );
	//shapes.push_back( std::make_shared<Shape>(new Shape (1,1) ));
/*	shapes.push_back( new Shape (2,3) );
	shapes.push_back( new Shape (3,4) );
	shapes.push_back( new Shape (4,5) );
*//*
	int i = 0;
	for (auto s : shapes) {
		std::cout << ++i << " : " << s->whatami() << std::endl;
	}
	*/
	std::cout << s1->whatami() << std::endl;
}
	