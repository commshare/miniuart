#include <iostream>

using namespace std;

int main()
{
	float f1=7.123456789;
	float f2=7.123456785;
	
	cout<<(f1!=f2 ? "not ":"")<<"same"<<endl;

	float g =1.0/3.0;
	double d=1.0/3.0; 
	
	cout<<(g!=d ? "not ":"")<<"same"<<endl;
	return 0;
}
