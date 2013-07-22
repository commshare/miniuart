#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	ifstream in("remainder.txt");
	for (string s,t,u;in>>s>>t;u="") {
		sort(s.begin(),s.end());
		sort(t.begin(),t.end());
		set_difference(s.begin(),s.end(),t.begin(),t.end(),back_inserter(u));
		cout << u << endl;
	}
	return 0;
}
