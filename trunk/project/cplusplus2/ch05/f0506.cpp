#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int bitSum(int a);
bool lessThanBitSum(int a,int b);

int main()
{
	int a[] = {33,61,12,19,14,71,78,59};
	vector<int> aa(a,a+8);
	sort(aa.begin(),aa.end(),lessThanBitSum);

	for (int i=0;i<aa.size();i++) {
		cout << aa[i] << " ";
	}
	cout << endl;

	return 0;
}

int bitSum(int a)
{
	int sum=0;
	for (int x=a;x;x/=10) sum+=x%10;
	return sum;
}

bool lessThanBitSum(int a,int b)
{
	return bitSum(a) < bitSum(b);
}
