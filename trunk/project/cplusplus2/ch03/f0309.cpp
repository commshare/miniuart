#include <iostream>
using namespace std;


int main()
{
	int array1[2][3]={1,2,3,4,5};
	int array2[2][3]={{1,2},{4}};
	
	cout<<"array1: ";
	for (int i=0;i<2;i++) {
		for (int j=0;j<3;j++) {
			cout<<array1[i][j]<<",";
		}
	}
	cout<<endl;
	
	cout<<"array2: ";
	for (int i=0;i<2;i++) {
		for (int j=0;j<3;j++) {
			cout<<array2[i][j]<<",";
		}
	}
	cout<<endl;
	return 0;
}
