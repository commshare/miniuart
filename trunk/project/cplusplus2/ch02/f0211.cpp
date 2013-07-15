#include <iostream>
#include <fstream>
using namespace std;


int main()
{
	ifstream in("a.in");
	ofstream out("a.out");

	for (string str;getline(in,str);) {
		out<<str<<endl;
		cout<<str<<endl;
	}
	return 0;
}
