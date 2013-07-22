#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ifstream in("string.txt");
	for (string s,t;in>>s>>t;) {
		int sc1 = count(s.begin(),s.end(),'1');		
		int sc0 = count(s.begin(),s.end(),'0');		
		int tc1 = count(t.begin(),t.end(),'1');	
		int tc0 = count(t.begin(),t.end(),'0');
		cout << (sc1==tc1 && sc0==tc0 ?"yes":"no") << endl;
	}
	return 0;
}
