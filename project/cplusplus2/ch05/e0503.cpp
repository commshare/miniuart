#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

int gcd1(int a,int b)
{
	if (a%b == 0) {
		return b;
	}
	return gcd1(b,a%b);
}

bool littlenum(int  a,int b)
{
	return a<b;
}

int main()
{
	vector<int> v;
	ifstream in("abc.in");
	for(string s;getline(in,s);) {
		istringstream sin(s);
		int a,b;
		sin >> a >> b;
		v.push_back(gcd1(a,b));
	}
	sort(v.begin(),v.end(),littlenum);
	
	for(int i = 0;i < v.size();i++) {
		cout << v[i] << " ";
	}
	cout << endl;
	
	return 0;
}
