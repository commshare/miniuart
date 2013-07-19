#include <iostream>
#include <vector>

using namespace std;

void print(const vector<int>& a);
void print();

bool proccess(const vector<int> & a);

int main()
{
	vector<int> a(10,5);

	if (proccess(a)) print(a);
	else print();
	
	return 0;
}

void print(const vector<int> &a)
{
	for (int i=0;i < a.size();i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
void print()
{
	cout << "failed" << endl;
	return ;
}

bool proccess(const vector<int> &a)
{
	int sum=0;
	for (int i=0;i<a.size();i++) sum+=a[i];
	if (sum>10) return true;
	else return false;
}

