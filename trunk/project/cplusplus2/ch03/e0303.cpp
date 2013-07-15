#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
	int a[]={6,3,7,1,4,8,2,9,11,5};
	vector<int> v(a,a+10);
	
	double fa,sum=0;
	for (vector<int>::iterator it=v.begin();it!=v.end();++it) {
		sum+=*it;
	}
	fa=sum/v.size();
	
	sum=0;
	for (int i=0;i<v.size();i++) {
		sum+=(v[i]-fa)*(v[i]-fa);
	}
	cout<<fixed<<sqrt(sum/v.size())<<endl;
	return 0;
}
