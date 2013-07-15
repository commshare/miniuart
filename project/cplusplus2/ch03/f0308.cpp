#include <iostream>
using namespace std;


int array1[5]={1,2,3};
int array2[5];

int main()
{
	int array3[5]={2};
	int array4[5];
	
	cout<<"array1: ";
	for (int i=0;i<5;i++) {
		cout<<array1[i]<<" ";
	}
	cout<<endl;

	cout<<"array2: ";
	for (int i=0;i<5;i++) {
		cout<<array2[i]<<" ";
	}
	cout<<endl;

	
	cout<<"array3: ";
	for (int i=0;i<5;i++) {
		cout<<array3[i]<<" ";
	}
	cout<<endl;
	
	cout<<"array4: ";
	for (int i=0;i<5;i++) {
		cout<<array4[i]<<" ";
	}
	cout<<endl;
	return 0;
}
