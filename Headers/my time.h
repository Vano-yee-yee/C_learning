#pragma once

struct Time
{
	unsigned char day; //[1; 31]
	unsigned char month; //[1; 12]
	unsigned char year; //[1; inf)
	unsigned char hour; //[0; 24]
	unsigned char minute; //[0; 60]
	unsigned char second; //[0; 60]
};

/**
* @brief ќпредел€ет високосный ли год
* @param year_: год
* @return 1: високосный год
* 0: иначе
*/
unsigned char Is_leap_year(const short year_);

/**
* @brief Ќаходит разницу во времени
* @param
* @return
*/
struct Time Diff_time(const struct Time* time1_, const struct Time* time2_);