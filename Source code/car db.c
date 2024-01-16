#include "car db.h"
#include <stdlib.h>
#include <time.h>

void print(struct car* restrict db_, const unsigned int amount_)
{
	unsigned int i=0;
	while(i<amount_)
	{
		printf("Mark: %s\nManufacture: %s\nLift weight: %u kg\nYear: %u\nRegistration date: %u.%u.%u\n\n", (*db_).mark,
			(*db_).manufacture,
			(*db_).lift_weight,
			(*db_).year,
			(*db_).regist_date.tm_mday,
			(*db_).regist_date.tm_mon,
			(*db_).regist_date.tm_year);
		db_+=1;
		i+=1;
	}
}
struct car* insert(FILE* restrict file_, const unsigned int max_)
{
	struct car* res=(struct car*)calloc(max_, sizeof(struct car));
	unsigned int i=0;
	while(i<max_
		&& fscanf(file_, "%[^\t]\t%[^\t]\t%u\t%u\t%u.%u.%u\n", &(*res).mark,
			&(*res).manufacture,
			&(*res).lift_weight,
			&(*res).year,
			&(*res).regist_date.tm_mday,
			&(*res).regist_date.tm_mon,
			&(*res).regist_date.tm_year))
	{
		res+=1;
		i+=1;
	}
	res-=i;
	return res;
}
struct car* query1(struct car* restrict db_, const unsigned int amount_)
{
	struct car* res=(struct car*)calloc(amount_, sizeof(struct car));
	const unsigned long long comp_time=time(NULL);
	unsigned int i=0;
	while(i<amount_)
	{
		if(mktime(&(*db_).regist_date)<=comp_time
			&& (*db_).lift_weight>3000)
		{
			*res=*db_;
			res+=1;
		}
		i+=1;
		db_+=1;
	}
	return res;
}