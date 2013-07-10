//----------------------------------
//f0201.cpp
//
//---------------------------------
#include <iostream>
using namespace std;

int main()
{
	double radius;
	cout << "Please input radius: "<<endl;
	cin >> radius;
	double result = radius * radius * 3.14 * 4;
	cout << "The result is " << result << endl;	
	return 0;
}
