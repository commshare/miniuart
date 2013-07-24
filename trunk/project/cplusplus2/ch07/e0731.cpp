#include <iostream>
#include <iomanip>
using namespace std;

void foo1()
{
	cout<<setw(4)<<"*"<<right;
	for (int i =1;i<=9;i++) {
		cout<<setw(5)<<i;
	}
	cout<<endl<<"--------------------------------------------------"	
	    <<endl;
	
	for (int i=1;i<=9;i++) {
		cout<<setw(4)<<right<<i;
		for (int j=1;j<=i;j++) {
			cout<<setw(5)<<i*j;
		}
		cout<<endl;
	}	
	return ;
}

