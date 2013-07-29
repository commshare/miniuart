#ifndef HEADER_MYMATRIX
#define HEADER_MYMATRIX

class Vector;
class Matrix {
	int *m;
	int szl,szr;
public:
	void set(int ,int);
	
	void remove() {
		delete m;
	}
	
	int sizeL() {
		return szl;
	}
	
	int sizeR() {
		return szr;
	}
	
	int &elem(int ,int );
	friend Vector multiply(Matrix &m,Vector &v);
};
#endif
