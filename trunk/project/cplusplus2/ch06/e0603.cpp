#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vs(255,0);
	vector<int> vt(255,0);
	
	ifstream in("e0603.txt");
	for (string s,t;getline(in,s) && getline(in,t);getline(in,s)) {
		if (s.length() != t.length()) {
			cout << "no\n" ;
		} else {
			vs = vector<int> (255,0);
			vt = vs;

			for (int i=0;i < s.length();i++) {
				unsigned char x;
				x = s[i];
				vs[x]++;
				x = t[i];
				vt[x]++;
			}
			cout << (vs==vt?"yes\n":"no\n");
		}
	}
	return 0;
}
