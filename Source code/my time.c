#include "my time.h"

unsigned char Is_leap_year(const short year_)
{
	if (year_% 400 == 0
		|| (year_% 4 == 0 && year_% 100 != 0))
		return 1;
	else
		return 0;
}
struct Time Diff_time(const struct Time* time1_, const struct Time* time2_)
{
	struct Time diff;
//	
}