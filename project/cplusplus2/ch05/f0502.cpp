#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> & a)
{
	for (int i=0;i<a.size();i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

vector<int> add(vector<int> &a,vector<int> &b)
{
	for (int i=0;i<a.size();i++) {
		a[i] += b[i];
	}
	return a;
}

int main()
{
	int aa[]={2,3,1,2,3,2,1},bb[]={5,3,1,1,6,2,2};
	vector<int> a(aa,aa+7),b(bb,bb+7);
	vector<int> c = add(a,b);

	print(a);
	print(b);
	print(c);

	return 0;
}
