#ifndef shape_h
#define shape_h

class shape {
public:
	shape() {

	}
	virtual ~shape() {
		std::cout << "Deleting shape!" << std::endl;
	}
	virtual double getArea(){
		return 0;
	}
private:

};

#endif