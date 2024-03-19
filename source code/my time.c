#include <my time.h>
#include <stdlib.h>

unsigned char is_leap_year(const short year_)
{
	if(year_%400==0
		|| (year_%4==0
			&& year_%100))
		return 1;
	else
		return 0;
}
static unsigned char compare_time(const Time* time1_, const Time* time2_, const unsigned char i_)
{
	unsigned int time1_v;
	unsigned int time2_v;
	switch(i_)
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
		return compare_time(time1_, time2_, i_+1);
	if(time1_v>time2_v)
		return 1;
	return 2;
}
Time* diff_time(const Time* time1_, const Time* time2_)
{
	Time* diff=realloc(NULL, sizeof(Time));
	if(!diff)
		return NULL;
	Time* min=realloc(NULL, sizeof(Time));
	if(!min)
		return NULL;
	const unsigned char old=compare_time(time1_, time2_, 0);
	switch(old)
	{
		case 1:
			*diff=*time1_;
			*min=*time2_;
			break;
		case 2:
			*diff=*time2_;
			*min=*time1_;
			break;
		default:
			min=realloc(min, 0);
/*			(*diff).day=0;
			(*diff).month=0;
			(*diff).year=0;
			(*diff).hour=0;
			(*diff).minute=0;
			(*diff).second=0;
			return diff;
*/
			diff=realloc(diff, 0);
			return NULL;
	}
	if((*diff).second<(*min).second)
	{
		(*diff).second+=60;
		(*diff).minute-=1;
	}
	(*diff).second-=(*min).second;
	if((*diff).minute<(*min).minute)
	{
		(*diff).minute+=60;
		(*diff).hour-=1;
	}
	(*diff).minute-=(*min).minute;
	if((*diff).hour<(*min).hour)
	{
		(*diff).hour+=24;
		(*diff).day-=1; 
	}
	(*diff).hour-=(*min).hour;
	if((*diff).day<(*min).day)
	{
		(*diff).month-=1;
		if((*diff).month==1)
		{
			if(is_leap_year((*diff).year+1))
				(*diff).day+=29;
			else
				(*diff).day+=28;
		}
		else if((*diff).month==7
			|| (*diff).month%2==0)
			(*diff).day+=31;
		else
			(*diff).day+=30;
	}
	(*diff).day-=(*min).day;
	if((*diff).month<(*min).month)
	{
		(*diff).month+=12;
		(*diff).year-=1;
	}
	(*diff).month-=(*min).month;
	(*diff).year-=(*min).year;
	min=realloc(min, 0);
	return diff;
}
void print_time(FILE* restrict stream_, const Time* time_)
{
	fprintf(stream_, "%u.%u.%u %u:%u:%u", (*time_).day+1,
		(*time_).month+1,
		(*time_).year+1,
		(*time_).hour,
		(*time_).minute,
		(*time_).second);
}