#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

bool mystrcmp(string a,string b)
{
	return a < b;
}

int main()
{
	ifstream in("e0506.txt");
	vector<string> vs;
	
	for (string s;getline(in,s);) {
		vs.push_back(s);
	}

	if (vs.size() > 0) {
		sort(vs.begin(),vs.end(),mystrcmp);
	}
	for (int i=0;i<vs.size();i++) {
		cout << vs[i] << endl;
	}
	return 0;
}
