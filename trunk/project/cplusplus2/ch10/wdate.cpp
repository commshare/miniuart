#include "wdate.h"

WDate::WDate(int a,int b,int c):Date(a,b,c)
{
	
};

string WDate::WDateString[] = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
};

int WDate::getWeekday() const
{
	Date dt(*this);
	Date t(2013,8,4);
	
	int df = dt - t;
	df = df % 7;

	if (df < 0) {
		return (int)(df + 7);
	}
	
	return int(df);	
}
