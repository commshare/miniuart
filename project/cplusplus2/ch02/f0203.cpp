//----------------------------------
//f0201.cpp
//
//---------------------------------
#include <iostream>
using namespace std;

void sphere();

int main()
{
	sphere();
	return 0;
}

void sphere()
{
	double radius;
	cout << "Please input radius: "<<endl;
	cin >> radius;
	if (radius < 0) return ;
	cout << "The result is " << radius * radius * 3.14 * 4 << endl;
	return ;
}
