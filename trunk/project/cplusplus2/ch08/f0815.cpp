#include <iostream>
#include <fstream>

using namespace std;

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
};

void Vector::set(int s) 
{
	sz = s;
	if (s<=0) {
		cerr<<"bad Vector size.\n";
		exit(1);
	}
	v = new int[s];
}

int& Vector::operator[](int i) 
{
	if (i<0 || i>= sz) {
		cerr << "Vector index out of range.\n";
		exit(1);
	}
		
	return v[i];
}

void Vector::display() 
{
	for (int i=0;i<sz;i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

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
};

void Matrix::set(int i,int j)
{
	szl = i; szr = j;
	if (i <=0 || j <= 0) {
		cerr << "bad Matrix size.\n";
		exit(1);
	}
	m = new int[i*j];
}

int& Matrix::elem(int i,int j) 
{
	if(i<0||szl<=i||j<0||szr<=j) {
		cerr<<"Matrix index out of range.\n";
		exit(0);
	}
	return m[i*szr+j];
}

Vector multiply(Matrix &m,Vector &v) 
{
	if (m.sizeR() != v.size()) {
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	
	Vector r;
	r.set(m.sizeL());
	
	for (int i=0;i<m.sizeL();i++) {
		r[i] = 0;
		for (int j=0;j<m.sizeR();j++) {
			r[i] += m.elem(i,j) * v[j];
		}
	}
	return r;
}

int main()
{
	ifstream in("f0815.txt");
	int x,y;
	in >> x >> y;
	Matrix ma;
	ma.set(x,y);
	
	for (int i=0;i<x;i++) {
		for (int j=0;j<y;j++) {
			in >> ma.elem(i,j);
		}
	}
	
	in>>x;
	Vector ve;
	ve.set(x);
	for (int i=0;i<x;i++) {
		in>>ve[i];
	}
	Vector vx = multiply(ma,ve);
	
	vx.display();
	ma.remove();
	ve.remove();
	vx.remove();
	
	return 0;
}
