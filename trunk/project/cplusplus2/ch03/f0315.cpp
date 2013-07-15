#include <iostream>

using namespace std;

int main()
{
	int int1=5;
	int &rInt=int1;
	
	cout<<"&int1: "<<&int1<<"   int1:"<<int1<<endl;
	cout<<"&rInt: "<<&rInt<<"   rInt:"<<rInt<<endl;

	int int2=8;
	rInt=int2;

	cout<<"&rInt: "<<&rInt<<"   rInt:"<<rInt<<endl;
	cout<<"&int1: "<<&int1<<"   int1:"<<int1<<endl;
	return 0;
}
