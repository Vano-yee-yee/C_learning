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
	while(fscanf(file_, "%"CAR_MARK_MAX_S"[^\t]%*c%"CAR_MANUFACTURE_MAX_S"[^\t]%*c%u\t%u\t%u.%u.%u\n", buf.mark,
			buf.manufacture,
			&buf.lift_weight,
			&buf.year,
			&buf.regist_date.tm_mday,
			&buf.regist_date.tm_mon,
			&buf.regist_date.tm_year)==7)
	{
		*amount_+=1;
		buf.regist_date.tm_mon-=1;
		buf.regist_date.tm_year-=1900;
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
	dif_t=mktime(&buf_t);

	unsigned int i=0;
	while(i<amount_)
	{
		struct tm db_date=(*db_).regist_date;
		if(mktime(&db_date)<=dif_t
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