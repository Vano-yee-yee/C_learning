#include "car db.h"
#include <stdlib.h>

void print(const struct car* db_, const unsigned int amount_)
{
	unsigned int i=0;
	while(i<amount_)
	{
		fprintf(stdout, "Mark: %s\nManufacture: %s\nLift weight: %u kg\nYear: %u\nRegistration date: %u\n\n", (*db_).mark,
			(*db_).manufacture,
			(*db_).lift_weight,
			(*db_).year_manuf,
			(*db_).regist_date);
		db_+=1;
		i+=1;
	}
}
struct car* insert(FILE* restrict file_, unsigned int* restrict amount_)
{
	*amount_=0;
	struct car* res=NULL;
	struct car buf;
	struct tm buf_regist;
	buf_regist.tm_sec=0;
	buf_regist.tm_min=0;
	buf_regist.tm_hour=0;
	fscanf(file_, "%*[^\n]\n");
	while(fscanf(file_, "%"CAR_MARK_MAX_S"[^\t]%*c%"CAR_MANUFACTURE_MAX_S"[^\t]%*c%u\t%u\t%u.%u.%u\n", buf.mark,
			buf.manufacture,
			&buf.lift_weight,
			&buf.year_manuf,
			&buf_regist.tm_mday,
			&buf_regist.tm_mon,
			&buf_regist.tm_year)==7)
	{
		*amount_+=1;
		buf_regist.tm_mon-=1;
		buf_regist.tm_year-=1900;
		buf.regist_date=mktime(&buf_regist);
		res=(struct car*)realloc(res, (*amount_)*sizeof(struct car));
		*(res+(*amount_)-1)=buf;
	}
//Change
	fclose(file_);
	return res;
}
struct car* query(const struct car* db_, const unsigned int amount_, unsigned int* restrict new_amount_)
{
	*new_amount_=0;
	struct car* res=NULL;

	time_t dif_t=time(NULL);
	struct tm buf_t=*localtime(&dif_t);
	buf_t.tm_year-=1;
	buf_t.tm_sec=0;
	buf_t.tm_min=0;
	buf_t.tm_hour=0;
	dif_t=mktime(&buf_t);

	unsigned int i=0;
	while(i<amount_)
	{
		if((*db_).regist_date<=dif_t
			&& (*db_).lift_weight>3000)
		{
			*new_amount_+=1;
			res=(struct car*)realloc(res, (*new_amount_)*sizeof(struct car));
			*(res+(*new_amount_)-1)=*db_;
		}
		db_+=1;
		i+=1;
	}
	return res;
}