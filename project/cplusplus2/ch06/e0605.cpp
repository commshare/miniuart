#include <iostream>
#include <fstream>

using namespace std;

void foo1(int n,int r,int m)
{
	cout<< ((m-1)/r + 1)<<" "<<(m-1)%r+1<<endl;
}

void foo2(int n,int r,int m)
{

	cout<<(m-1)%r+1<<" "<< ((m-1)/r + 1)<<endl;
}

void foo3(int n,int r,int m)
{
	if (r&1) {
		int c,l;
		l = (m-1)/r;
		c = (m-1)%r;	
		if (c <= r/2) {
			c = c*2+1;
			l = l*2+1;
		} else {
			c = (c-r/2)*2+2;
			l = (l+1)*2;
		}
		cout << l << " " << c <<endl;
	}
}

void foo4(int n,int r,int m)
{
	if (r&1) {
		int c,l;
		l = (m-1)/r;
		c = (m-1)%r;	
		if (c <= r/2) {
			c = c*2+1;
			l = l*2+1;
		} else {
			c = (c-r/2)*2+2;
			l = (l+1)*2;
		}
		cout << c << " " << l <<endl;
	}
}

int main()
{
	ifstream in("e0605.txt");
	int k;

	in >> k;
	for (int i=0;i<k;i++) {
		int n,x,y,r,m;
		in >> n >> x >> y >> r >> m;
		//cout<< n<<" "<<x <<" "<<y<<" "<<r<<" "<<m<< endl;
		if ((x == 1) && (y==1)) {
			foo1(n,r,m);
		} else if ((x == 1) && (y==2)) {
			foo2(n,r,m);
		} else if((x== 2) && (y==1)) {
			foo3(n,r,m);
		} else if ((x==2) && (y==2)) {
			foo4(n,r,m);
		}
	}
	return 0;

}
