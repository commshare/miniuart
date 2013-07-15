#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	double sum=0,item=1;
	for (int denom=1,sign=1;abs(item)>1e-6;sign*=-1,denom+=2) {
		item=sign/double(denom);
		sum+=item;
	}
	cout<<"Pi = "<<fixed<<sum*4<<endl;
	return 0;
}
