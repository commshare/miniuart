#ifndef HEADER_MYVECTOR
#define HEADER_MYVECTOR

class Matrix;
class Vector {
	int *v;
	int sz;
public:
	void remove() {
		delete v;
	}
	
	int size() {
		return sz;
	}
	
	void set(int);
	
	void display();
	
	int &operator[](int i);
	
	friend Vector multiply(Matrix &m,Vector &v);
	
};

#endif
