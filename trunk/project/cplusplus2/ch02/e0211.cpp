#include <iostream>

using namespace std;

int foo1()
{
	for (int x=1;x<10;x++) {
		for(int y=1;y<20;y++) {
			int z=100-x*10-y*5;
			if (z>=1)
			cout<<x<<"  "<<y<<"  "<<z<<endl;
		} 
	}
	return 0;
}

int main()
{
	foo1();	
	return 0;
}
