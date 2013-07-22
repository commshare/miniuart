#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ifstream in("string.txt");
	for (string s,t;in>>s>>t;) {
		int sc0 = count(s.begin(),s.end(),'0');		
		int tc0 = count(t.begin(),t.end(),'0');
		cout << (sc0==tc0 && s.length()==t.length() ?"yes":"no") << endl;
	}
	return 0;
}
