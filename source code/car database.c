#include <car database.h>
#include <time.h>
#include <stdlib.h>

#define CAR_MARK_MAX 50
#define CAR_MARK_MAX_S "50"
#define CAR_MANUFACTURE_MAX 100
#define CAR_MANUFACTURE_MAX_S "100"

struct Car
{
	char mark[CAR_MARK_MAX+1];
	char manufacture[CAR_MANUFACTURE_MAX+1];
	unsigned short lift_weight;
	unsigned short year_manuf;
	time_t regist_date;
};

Car* insert_car(FILE* restrict file_, unsigned int* restrict amount_)
{
	*amount_=0;
	Car* res=NULL;
	Car buf;
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
		res=(Car*)realloc(res, (*amount_)*sizeof(Car));
		if(!res)
			return NULL;
		*(res+(*amount_)-1)=buf;
	}
//Change
	fclose(file_);
	return res;
}

#undef CAR_MARK_MAX
#undef CAR_MARK_MAX_S
#undef CAR_MANUFACTURE_MAX
#undef CAR_MANUFACTURE_MAX_S

void print_car(FILE* restrict stream_, const Car* db_, const unsigned int amount_)
{
	unsigned int i=0;
	while(i<amount_)
	{
		const struct tm regist_date2=*localtime(&(*db_).regist_date);
		fprintf(stream_, "Mark: %s\nManufacture: %s\nLift weight: %u kg\nYear: %u\nRegistration date: %u.%u.%u\n\n", (*db_).mark,
			(*db_).manufacture,
			(*db_).lift_weight,
			(*db_).year_manuf,
			regist_date2.tm_mday,
			regist_date2.tm_mon+1,
			regist_date2.tm_year+1900);
		db_+=1;
		i+=1;
	}
}
Car* query_car(const Car* db_, const unsigned int amount_, unsigned int* restrict new_amount_)
{
	*new_amount_=0;
	Car* res=NULL;

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
			res=(Car*)realloc(res, (*new_amount_)*sizeof(Car));
			if(!res)
				return NULL;
			*(res+(*new_amount_)-1)=*db_;
		}
		db_+=1;
		i+=1;
	}
	return res;
}