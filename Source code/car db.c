#include "car db.h"

void print_struct(struct car* db_, unsigned short amount_)
{
	unsigned short i=0;
	while(i<amount_)
	{
		printf("Mark: %s\nManufacture: %s\nLift weight: %u\nYear: %u\nRegistration date: %u.%u.%u\n", (*db_).mark,
			(*db_).manufacture,
			(*db_).lift_weight,
			(*db_).year,
			(*db_).regist_date.tm_mday,
			(*db_).regist_date.tm_mon,
			(*db_).regist_date.tm_year);
		i+=1;
	}
}

struct car* insert(const FILE* file_)
{
	struct car db[200];
	unsigned short i=0;
	while(fscanf((FILE*)file_, "%[^\n]\n%[^\n]\n%u\n%u\n%u.%u.%u\n\n", db[i].mark,
		&db[i].manufacture,
		&db[i].lift_weight,
		&db[i].year,
		&db[i].regist_date.tm_mday,
		&db[i].regist_date.tm_mon,
		&db[i].regist_date.tm_year)==7)
	{
		db[i].regist_date.tm_mon+=1;
		i+=1;
	}
	print_struct(db, 1);
	return db;
}
struct car* query1(const struct car* db_, const unsigned short amount_)
{
}