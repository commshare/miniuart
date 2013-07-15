#include <iostream>

using namespace std;


int main()
{
	int array1[6];
	for (int i=0;i<6;i++) {
		array1[i]=i*2;
	}
	
	for (int *ip=array1;ip<array1+6;ip++) {
		cout<<ip<<":"<<*ip<<endl;
	}
	return 0;
}
