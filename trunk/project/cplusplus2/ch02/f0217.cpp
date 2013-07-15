#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	double sum=0,item=1;
	for (int i=1;abs(item)>1e-6;i++) {
		item*=(-1.0)*(2*i-3)/(2*i-1);
		sum+=item;
	}	

	cout << "Pi = "<<setiosflags(ios::fixed)<<setprecision(6)<<sum*4<<endl;

	return 0;
}
