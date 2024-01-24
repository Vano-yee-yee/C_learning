#include <stdio.h>
#include "euler.h"
#include "str.h"
#include "functions.h"
#include "car db.h"

#define EULER_PROJECT fprintf(stdout, "Task 1 %u\n", Problem_1(1000, (char[]){3, 5}, 2)); \
	fprintf(stdout, "Task 2 %u\n", Problem_2(4000000)); \
	fprintf(stdout, "Task 3 %llu\n", Problem_3(600851475143)); \
	fprintf(stdout, "Task 4 %u\n", Problem_4(100, 999)); \
	fprintf(stdout, "Task 5 %u\n", Problem_5(1, 20));
#define MODULE_1_EXTRA fprintf(stdout, "Euler function(%d)=%d\n", 81, euler_fun(81)); \
	fprintf(stdout, "Taylor e^2=%Lf\n", e_taylor(1., 0.001));
#define MY_STR_FUN char str[24]="Hello Word!"; \
	char str2[13]=" Hehehe hoho"; \
	char str3[5]="Word"; \
	fprintf(stdout, "strlen %u\n", my_strlen(str)); \
	fprintf(stdout, "   cat \"%s\"\n", my_strcat(str, str2)); \
	fprintf(stdout, "   cmp \"%s\" \"%s\" %d\n", str, str2, my_strcmp(str, str2)); \
	fprintf(stdout, "   str \"%s\" \"%s\" \"%s\"\n", str2, str3, my_strstr(str2, str3)); \
	fprintf(stdout, "   cpy \"%s\" \"%s\" \"%s\"\n", str, str3, my_strcpy(str, str3)); \
	\
	FILE* f=fopen("Source code/functions.c", "r"); \
	if(!f) \
	{ \
		fprintf(stderr, "Unable to open file\n"); \
		return 0; \
	} \
	char line[101]; \
	unsigned int i=0; \
	while(i<100) \
	{ \
		line[i]=' '; \
		i+=1; \
	} \
	fprintf(stdout, "symbols=%u \"%s\"\n", my_fgetline(line, f), line); \
	fclose(f);
#define MODULE_2 char str4[9]="abcdefgh"; \
	fprintf(stdout, "\"%s\" ", str4); \
	chg_by_pair(str4); \
	fprintf(stdout, "\"%s\"\n", str4); \
	\
	FILE* f2=fopen("Resources/cars.txt", "r"); \
	if(!f2) \
	{ \
		fprintf(stderr, "Unable to open file 2\n"); \
		return 0; \
	} \
	unsigned char db_size; \
	struct car* db=insert(f2, (unsigned int*)&db_size); \
	fprintf(stdout, "Success\n"); \
	fclose(f2); \
	print(db, db_size);

int main()
{
//	EULER_PROJECT
//	MODULE_1_EXTRA
//	cows_and_bulls(4);
//	MY_STR_FUN
	MODULE_2
	return 0;
}