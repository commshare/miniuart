#include <iostream>
#include <fstream>

using namespace std;

int s[232] = {0};

/*
 * 1    10    100  1000  10000
 * 1    2     4    7     11
 * 1    2     3    4     5
 *
 * m(n) = m(n-1)+n-1   n>=1   
 * m(1) = 1
 * ->  m(n) = (n-1)*n/2 + 1
 * */
int xm(int n)
{
	return ((n-1)*n)/2+1;
}

/*binary search*/
int foo1(int a[],int n,int k)
{
	int l,h,m;
	l=1;h=n;
	
	while (l <= h) {
		m = (l+h)/2;
		
		if (a[m] == k) {
			return 1;
		} else if (a[m] > k) {
			h = m-1;
		} else {
			l = m+1;
		}
	}
	return 0;
}

int main()
{
	ifstream in("e0602.txt");
	int num;
	in >> num;
	
	/*init*/
	for (int i=1;i<sizeof(s)/sizeof(s[0]);i++) {
		s[i] = xm(i);
	}

	
	for(int i;in>>i;) {
		cout << (foo1(s,sizeof(s)/sizeof(s[0]),i)) << " ";
	}
	cout << endl;
}

