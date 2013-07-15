#include <iostream>

using namespace std;

int foo1(int x)
{
	int n = (x+1)/2;
	for (int i=1;i<n;i++) {
		for (int a=0;a<n-i;a++) {
			cout<<" ";
		}		
		for (int b=0;b<2*i-1;b++ ){
			cout<<"%";
		}
		cout<<endl;
	}

	/*up*/
	for (int i = 0;i<2*n-1;i++) {
		cout<<"%";
	}
	cout<<endl;

	/*down*/	
	for (int i=1;i<n;i++) {
		for (int a=0;a<i;a++) {
			cout<<" ";		
		}
		for (int b=0;b<2*(n-i)-1;b++) {
			cout << "%";
		}
		cout << endl;
	}
	return 0;

}

int main()
{
	foo1(1);	
	foo1(3);	
	foo1(5);		
	foo1(7);	
	foo1(10);
	foo1(19);
	return 0;
}
