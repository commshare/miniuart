#include <iostream>
#include <ctime>

using namespace std;

int calc1(int a,int b)
{
	return a+b;
}

inline int calc2(int a,int b)
{
	return a+b;
}

#define calc3(a,b) ((a)+(b))

int main()
{
	int z[1000],y[1000],x[1000];
	int i,j,k;	

	clock_t t = clock();
	for (i=0;i<1000;i++) {
		for (j=0;j<1000;j++) {
			for (k=0;k<1000;k++) {
				z[i] = calc1(x[j],y[k]);
			}
		}
	}
	cout << "Not using inline: " << (clock()-t)/(CLOCKS_PER_SEC *1.0) << "seconds\n";

	t = clock();
	for (i=0;i<1000;i++) {
		for (j=0;j<1000;j++) {
			for (k=0;k<1000;k++) {
				z[i] = calc2(x[j],y[k]);
			}
		}
	}
	cout << "    using inline: " << (clock()-t)/(CLOCKS_PER_SEC*1.0) << "seconds\n";

	t = clock();
	for (i=0;i<1000;i++) {
		for (j=0;j<1000;j++) {
			for (k=0;k<1000;k++) {
				z[i] = calc3(x[j],y[k]);
			}
		}
	}
	cout << "    using  macro: " << (clock()-t)/(CLOCKS_PER_SEC*1.0) << "seconds\n";

	return 0;
}
