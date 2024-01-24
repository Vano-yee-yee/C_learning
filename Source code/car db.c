#include "car db.h"
#include <stdlib.h>

void print(const struct car* db_, const unsigned int amount_)
{
	unsigned int i=0;
	while(i<amount_)
	{
		fprintf(stdout, "Mark: %s\nManufacture: %s\nLift weight: %u kg\nYear: %u\nRegistration date: %u.%u.%u\n\n", (*db_).mark,
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
struct car* insert(FILE* restrict file_, unsigned int* restrict amount_)
{
	*amount_=0;
	struct car* res=NULL;
	struct car buf;
	fscanf(file_, "%*[^\n]\n");
	while(fscanf(file_, "%[^\t]%*c%[^\t]%*c%u\t%u\t%u.%u.%u\n", buf.mark,
			buf.manufacture,
			&buf.lift_weight,
			&buf.year,
			&buf.regist_date.tm_mday,
			&buf.regist_date.tm_mon,
			&buf.regist_date.tm_year)==7)
	{
		*amount_+=1;
		res=(struct car*)realloc(res, (*amount_)*sizeof(struct car));
		*(res+(*amount_)-1)=buf;
	}
	return res;
}
/*struct car* query1(const struct car* db_, const unsigned int amount_);
{
	struct car* res;
	const unsigned long long comp_time=time(NULL);
	unsigned int i=0;
	while(i<amount_)
	{
		if(mktime(&(*db_).regist_date)<=comp_time
			&& (*db_).lift_weight>3000)
		{
			if(res==NULL)
				res=(struct car*)calloc(1, sizeof(struct car));
			else
				res=(struct car*)realloc(res, sizeof(struct car));
			*res=*db_;
			res+=1;
		}
		i+=1;
		db_+=1;
	}
	return res;
}
*/