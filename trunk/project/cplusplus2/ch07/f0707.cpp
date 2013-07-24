#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

typedef vector< vector<int> > Mat;
void input(istream &in,Mat &a);
Mat matAdd(const Mat &a,const Mat &b);
void print(const Mat &a);

int main()
{
	ifstream in("f0707.txt");
	for (int row,col;in>>row>>col;) {
		Mat a(row,vector<int> (col));
		Mat b=a;
		input(in,a);
		input(in,b);
		print(matAdd(a,b));
	}
	return 0;
}

void input(istream &in,Mat &a)
{
	for (int i=0;i<a.size();++i) {
		for (int j=0;j<a[0].size();j++) {
			in >> a[i][j];
		}
	}
}

Mat matAdd(const Mat &a,const Mat &b)
{
	Mat c =a;
	for (int i=0;i<a.size();++i) {
		for (int j=0;j<a[0].size();j++) {
			c[i][j] = a[i][j] + b[i][j];
		}
	}
	return c;
}

void print(const Mat &a)
{

	for (int i=0;i<a.size();++i) {
		for (int j=0;j<a[0].size();j++) {
			cout << setw(4) << a[i][j];
		}
		cout << endl;
	}
}

