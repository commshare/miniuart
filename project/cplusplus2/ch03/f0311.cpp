#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

typedef vector<vector<int> > Mat;

void myInput(Mat & a);
void mySort(Mat &a);
void muPrint(Mat &a);

void myInput(Mat & x)
{
	ifstream in("aaa.txt");
	for (string s;getline(in,s);) {
		int a;
		vector<int> b;
		for(istringstream sin(s);sin>>a;) {
			b.push_back(a);
		}
		x.push_back(b);
	}
}
void mySort(Mat &a)
{
	for (int i=1;i<a.size();i++) {
		for (int j=0;j<a.size()-i;j++) {
			if (a[j].size() > a[j+1].size()) {
				a[j].swap(a[j+1]);
			}
		}
	}
	return;
}
void myPrint(Mat &a)
{
	for (int i=0;i<a.size();i++) {
		for (int j=0;j<a[i].size();j++) {
			cout<<a[i][j]<<",";
		}
		cout<<endl;
	}
}

int main()
{
	vector<vector<int> > a;
	myInput(a);
	mySort(a);
	myPrint(a);
	return 0;
}

