#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Vector {
	int *v;
	int sz;
public:
	Vector(istream & in);
	Vector(const Vector & s);
	Vector(int n);

	~Vector() {
		delete v;
        cout << "Vector Destructing...\n";
	}

	int size() {
		return sz;
	}
	
	void display();
	
	int &operator[](int i);
};

Vector::Vector(istream &in)
{
	in >> sz;
	v = new int[sz];	
	for (int i=0;i < sz;i++) {
		in >> v[i];
	}
	cout << "Vector Constructor #1" << endl;
}

Vector::Vector(const Vector & s)
{
	sz = s.sz;
	v = new int[sz];
	for (int i=0;i < sz;i++) {
		v[i] = s.v[i];
	}
	cout << "Vector Constructor #2" << endl;
}

Vector::Vector(int n)
{
	sz = n;
	v = new int[sz];
	for (int i=0;i<sz;i++) {
		v[i] = 0;
	}
	cout << "Vector Constructor #3" << endl;
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
	Matrix(istream & in);
	Matrix(const Matrix &m);
	~Matrix() {
        cout << "Matrix destructing...\n";
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

Matrix::Matrix(istream & in)
{
	in >> szl >> szr;
	m = new int[szl*szr];
	for (int i=0;i < szl;i++) {
		for (int j=0;j < szr;j++) {
			in >> m[i*szr+j];
		}
	}
	cout << "Matrix Constructor #1" <<endl;
}

Matrix::Matrix(const Matrix & ma)
{
	szl = ma.szl;
	szr = ma.szr;
	m = new int[szl*szr];
	
	for (int i=0;i < szl;i++) {
		for (int j=0;j < szr;j++) {
			m[i*szr+j] = ma.m[i*szr+j];
		}
	}
	cout << "Matrix Constructor #2" <<endl;
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
	
	Vector r(m.sizeL());
	
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
	ifstream in("e0904.txt");
	Matrix ma(in);
	Vector ve(in);
	multiply(ma,ve).display();	
	return 0;
}
