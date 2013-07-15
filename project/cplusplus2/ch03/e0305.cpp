#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int c[]={4,9,6,2,8,7,3};
	for (string s;getline(cin,s);) {
		char ch;
		int i = 0;
		string out,o;
		for (int j=0;j<s.size();j++) {
			ch=s[j];
			if (i >= 7) {
				i=0;
			}
			ch += c[i++];
			if (ch > 'z') {
				ch = ch - 'z' + ' ';
			}
			out.push_back(ch);
		} 
		cout<<out<<endl;
		
		i = 0;	
		for (int j=0;j<out.size();j++) {
			ch=out[j];
			if (i >= 7) {
				i=0;
			}
			ch -= c[i++];
			if (ch < ' ') {
				ch = ch + 'z' - ' ';
			}
			o.push_back(ch);
		}
		cout<<o<<endl;
	}
	return 0;
}
