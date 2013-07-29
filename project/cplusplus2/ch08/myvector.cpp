#include "myvector.h"
#include <iostream>

using namespace std;

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