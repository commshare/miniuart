#include <iostream>

using namespace std;

int main()
{
	/*long int,int ,char ,bool
 	 *float,double,long double*/
	cout<<"long int :"<<sizeof(long int)<<" byte "<<sizeof(long int)*8<<" bit\n";
	cout<<"     int :"<<sizeof(int)<<" byte "<<sizeof(int)*8<<" bit\n";
	cout<<"    char :"<<sizeof(char)<<" byte "<<sizeof(char)*8<<" bit\n";
	cout<<"   short :"<<sizeof(bool)<<" byte "<<sizeof(short)*8<<" bit\n";
	cout<<"    bool :"<<sizeof(bool)<<" byte "<<sizeof(bool)*8<<" bit\n";
	cout<<"   float :"<<sizeof(float)<<" byte "<<sizeof(float)*8<<" bit\n";
	cout<<"  double :"<<sizeof(double)<<" byte "<<sizeof(double)*8<<" bit\n";
	cout<<"long double :"<<sizeof(long double)<<" byte "<<sizeof(long double)*8<<" bit\n";
	return 0;
}
