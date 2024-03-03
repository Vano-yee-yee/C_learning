#include <my time.h>

unsigned char is_leap_year(const short year_)
{
	if (year_%400==0
		|| (year_%4==0 && year_%100!=0))
		return 1;
	else
		return 0;
}
static unsigned char compare_time(const Time* time1_, const Time* time2_, unsigned char i)
{
	unsigned int time1_v;
	unsigned int time2_v;
	switch(i)
	{
		case 0:
			time1_v=(*time1_).year;
			time2_v=(*time2_).year;
			break;
		case 1:
			time1_v=(*time1_).month;
			time2_v=(*time2_).month;
			break;
		case 2:
			time1_v=(*time1_).day;
			time2_v=(*time2_).day;
			break;
		case 3:
			time1_v=(*time1_).hour;
			time2_v=(*time2_).hour;
			break;
		case 4:
			time1_v=(*time1_).minute;
			time2_v=(*time2_).minute;
			break;
		case 5:
			time1_v=(*time1_).second;
			time2_v=(*time2_).second;
			break;
		default:
			return 0;
	}
	if(time1_v==time2_v)
		return compare_time(time1_, time2_, i+1);
	if(time1_v>time2_v)
		return 1;
	return 2;
}
Time diff_time(const Time* time1_, const Time* time2_)
{
	Time diff;
	Time* min;
	diff.year=0;
	diff.month=0;
	diff.day=0;
	diff.hour=0;
	diff.minute=0;
	diff.second=0;

	unsigned char old=compare_time(time1_, time2_, 0);
	switch(old)
	{
		case 1:
			diff=*time1_;
			min=(Time*)time2_;
			break;
		case 2:
			diff=*time2_;
			min=(Time*)time1_;
			break;
	}
//Not for all times!!
	if(diff.second<(*min).second)
	{
		diff.second+=60;
		diff.minute-=1;
	}
	diff.second-=(*min).second;
	if(diff.minute<(*min).minute)
	{
		diff.minute+=60;
		diff.hour-=1;
	}
	diff.minute-=(*min).minute;
	if(diff.hour<(*min).hour)
	{
		diff.hour+=24;
		diff.day-=1;
	}
	diff.hour-=(*min).hour;
	if(diff.day<(*min).day)
	{
		diff.month-=1;
		if(diff.month==1)
		{
			if(is_leap_year(diff.year+1))
				diff.day+=29;
			else
				diff.day+=28;
		}
		else if(diff.month==7
			|| diff.month%2==0)
			diff.day+=31;
		else
			diff.day+=30;
	}
	diff.day-=(*min).day;
	if(diff.month<(*min).month)
	{
		diff.month+=12;
		diff.year-=1;
	}
	diff.month-=(*min).month;
	diff.year-=(*min).year;
	return diff;
}
void print_time(FILE* restrict stream_, const Time* time_)
{
	fprintf(stream_, "%u.%u.%u %u:%u:%u\n", (*time_).day+1,
		(*time_).month+1,
		(*time_).year+1,
		(*time_).hour,
		(*time_).minute,
		(*time_).second);
}