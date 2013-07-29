#include <iostream>
#include <fstream>

#include "myvector.h"
#include "mymatrix.h"

using namespace std;

int main()
{
	ifstream in("f0816.txt");
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