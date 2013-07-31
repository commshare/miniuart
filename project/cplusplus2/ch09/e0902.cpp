#include <iostream>
#include <cstdlib>

using namespace std;

class Vector {
	int size;
	int * buffer;
public:
	Vector(int s=100);
	Vector(const Vector & v);
	int & elem(int ndx);
	void display();
	void set();
	~Vector();
};

Vector::Vector(int s) 
{
	buffer = new int[size = s];
	for (int i=0;i<size;i++) {
		buffer[i] = i*i;
	}
}

Vector::Vector(const Vector & v)
{
	buffer = new int[size=v.size];
	for (int i=0;i < size;i++) {
		buffer[i] = v.buffer[i];
	}
}

int & Vector::elem(int ndx)
{
	if (ndx < 0 || ndx >= size) {
		cout << "error in index" << endl;
		exit(1);
	}
	return buffer[ndx];
}

void Vector::display()
{
	for (int i=0;i < size;i++) {
		cout << buffer[i] << endl;
	}
}

void Vector::set()
{
	for (int j=0;j < size;j++) {
		buffer[j] = j+1;
	}
}

Vector::~Vector() 
{
	delete []buffer;
}

int main()
{
	Vector a(10);
	Vector b(a);

	a.set();
	b.display();

	return 0;
}



