#include "mymatrix.h"
#include "myvector.h"

#include <iostream>

using namespace std;

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
	if (m.szr != v.size()) {
		cerr << "bad multiply Matrix with Vector.\n";
		exit(1);
	}
	
	Vector r;
	r.set(m.szl);
	
	for (int i=0;i<m.szl;i++) {
		r[i] = 0;
		for (int j=0;j<m.szr;j++) {
			r[i] += m.m[i*m.szr+j] * v[j];
		}
	}
	return r;
}
