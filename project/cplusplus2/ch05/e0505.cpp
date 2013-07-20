#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int calc(int n)
{
	int sum;
	for (sum=0;n;) {
		sum += (n%10)*(n%10);
		n = n/10;
	}
	return sum;
}

bool little(int a,int b)
{
	return calc(a) < calc(b);
}

void print()
{
	cout << "0" << endl;
}

void print(const vector<int> &v)
{
	for (int i=0;i<v.size();i++) {
		cout << v[i] << " ";
	}
	cout << endl;
}

int main()
{
	ifstream in("e0505.txt");
	//input
	vector<int> v;
	for (string s;getline(in,s);) {
		istringstream sin(s);
		for (int a;sin>>a;) {
			v.push_back(a);
		}
	}
	if (v.size() == 0) {
		print();
		return 0;
	}	
	
	//sort
	sort(v.begin(),v.end(),little);
	print(v);
}
