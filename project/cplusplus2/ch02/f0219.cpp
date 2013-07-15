#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double sum=0,item=1;
	int denom=1,sign=1;
	while(abs(item)>1e-6) { 
		item=sign/double(denom);
		sum+=item;
		sign*=-1;denom+=2;
	}
	cout<<"Pi = "<<fixed<<sum*4<<endl;
	return 0;
}
