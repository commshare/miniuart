#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void foo1()
{
	long long x;
	ifstream in("change.in");
	
	for (string s;getline(in,s);){
		x = 0;
		if (s == "-1") {
			break;
		}
		for (int i=0,n=s.size();i<n;i++) {
			x <<= 1;
			x += (s[i]-'0');
		}
		cout << x << endl;
	}
	return ;
}

int main()
{
	foo1();
	return 0;
}
