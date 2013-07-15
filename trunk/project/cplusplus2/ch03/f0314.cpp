#include <iostream>

using namespace std;

int main()
{
	int a=78,c=18;
	const int *cp=&a;
	const int* const icp=&c;
	
	a=60;c=28;
	cout<<" ip=>"<<*cp<<endl;
	cout<<"icp=>"<<*icp<<endl;
	return 0;
}
