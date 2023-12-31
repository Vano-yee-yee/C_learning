#include "car db.h"

void print(const struct car* db_, const unsigned int amount_)
{
	unsigned int i=0;
	while(i<amount_)
	{
		printf("Mark: %s\nManufacture: %s\nLift weight: %u\nYear: %u\nRegistration date: %u.%u.%u\n\n", (*db_).mark,
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
void insert(struct car* res_, const FILE* file_, const unsigned int max_)
{
	unsigned int i=0;
	while(i<max_
		&& fscanf(file_, "%[^\t]\t%[^\t]\t%u\t%u\t%u.%u.%u\n", &(*res_).mark,
			&(*res_).manufacture,
			&(*res_).lift_weight,
			&(*res_).year,
			&(*res_).regist_date.tm_mday,
			&(*res_).regist_date.tm_mon,
			&(*res_).regist_date.tm_year))
	{
		res_+=1;
		i+=1;
	}
}
void query1(struct car* res_, const struct car* db_, const unsigned int amount_)
{
}