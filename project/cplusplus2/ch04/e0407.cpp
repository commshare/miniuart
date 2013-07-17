#include <iostream>

using namespace std;

int main()
{
	int a,b,c;
	int s,w,t;
#if 0
	s=w=t=0;
	a=-1;b=3;c=3;

	if (c>0) {
		s=a+b;
	}
	if (a<=0) {
		if (b>0) {
			if (c <= 0) {
				w = a-b;
			}
		}
	} else if (c>0) {	
		w=a-b;
	}else { 
		t=c;
	}
#else
	s = w = t = 0;
	a=-1;b=3;c=3;
	if (c > 0) {
		s = a+b;
		if (a > 0) {
			w = a+b;
		}
	} else {
		if (a > 0) {
			t = c;
		} else {
			w = a-b;
		}
	}
#endif
	cout<<s<<','<<w<<','<<t<<endl;
	return 0;
}
