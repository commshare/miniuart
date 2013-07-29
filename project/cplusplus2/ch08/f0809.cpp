#include "point.h"
#include <iostream>

using namespace std;

int main()
{
	Point s,t; 
	
	s.set(2,5);
	t.set(3,1);
	
	cout << s+t;
	
	return 0;
}
