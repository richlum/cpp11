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
	virtual ~Shape(){
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

typedef  std::vector<std::shared_ptr<Shape>> shapevector;
typedef  std::vector<std::weak_ptr<Shape>> wkshapevector;

shapevector* populate(int qty){
	shapevector* shapes = new std::vector<std::shared_ptr<Shape>>(); // = new std::vector<Shape*>();
	for (int i = 0;i<qty;i++){
		shapes->push_back( std::move(std::make_shared<Shape>( i,i+1 )));
		std::cout << "added " << i << " " << shapes->back().use_count() << std::endl;
	}
	return shapes;
}

wkshapevector* copyto(shapevector* sv) {
	wkshapevector* wsv = new wkshapevector();
	for (auto s : *sv) {
		std::weak_ptr<Shape> ws(s);
		wsv->push_back(ws);
	}	
	return wsv;
}

template<typename T>
T* move(int x , int y, T* sv) {
	for (std::shared_ptr<Shape> s : *sv ) {
		(s)->setPos( (s)->getX() + x, (s)->getY() + y);
	}
	return sv;

}
template<>
wkshapevector* move(int x , int y, wkshapevector* wsv) {
	for (auto s: *wsv){
		if (auto w = s.lock()){
			w->setPos( w->getX() + x, w->getY() + y);
		}
	}
	return wsv;
}

void empty (shapevector* sv){

	for (std::shared_ptr<Shape> s : *sv) {
		std::cout << "b4 empty, usecount = " << s.use_count() << std::endl; 
		s.reset();
		std::cout << "after empty, usecount = " << s.use_count() << std::endl; 
	}
	for (int i = 0;i<sv->size();i++){
		//auto s = dynamic_cast<std::shared_ptr<Shape>*>( sv->pop_back() );
		auto s = ( sv->back() );
		sv->pop_back();
		std::cout << i << " pooped, count= " << s.use_count() << std::endl;
	}
}

template<typename T>
void show(T* sv) {
	int i = 0;
	for (auto s : *sv) {
		std::cout << ++i <<  " "   <<  s.use_count()   << " : " << (s)->whatami() << std::endl;
	}
}
template<>
void show(wkshapevector* sv) {
	int i = 0;
	for (auto s : *sv) {
		//std::cout << ++i <<  " "   <<  s.use_count()   << " : " << (s)->whatami() << std::endl;
		if (auto sh_vec = s.lock()){
			std::cout << ++i <<  " fr wk "   <<  sh_vec.use_count()   << " : " << (sh_vec)->whatami() << std::endl;
		}
	}
}




int main(int argc, char** argv) {

	shapevector* shapes = populate(5);
	wkshapevector* wrefshapes = copyto(shapes) ;

	show<shapevector> (shapes);
	show<wkshapevector> (wrefshapes);
	//shapes = move<shapevector>(3,2,shapes); 
	wrefshapes = move<wkshapevector>(3,2,wrefshapes); 
	//std::shared_ptr<Shape>  shape3 = (*shapes)[3];
	show<shapevector> (shapes);	
	empty (shapes);
	show<shapevector> (shapes);	
	//std::cout << s1->whatami() << std::endl;
	//std::cout << (shape3)->whatami() << " usecount = " << shape3.use_count() << std::endl;
	
}