#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

int main()
{
	ifstream in("aa.txt");
	for (string s;getline(in,s);){
		int a,sum=0;
		for (istringstream sin(s);sin>>a;sum+=a);
		cout<<sum<<endl;
	}
	return 0;
}
