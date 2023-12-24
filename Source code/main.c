#include <stdio.h>
#include "euler.h"
#include "str.h"
#include "functions.h"
#include "cows and bulls.h"

#define EULER_PROJECT printf("Task 1 %u\n", Problem_1(1000, (char[]){3, 5}, 2)); \
	printf("Task 2 %u\n", Problem_2(4000000)); \
	printf("Task 3 %llu\n", Problem_3(600851475143)); \
	printf("Task 4 %u\n", Problem_4(100, 999)); \
	printf("Task 5 %u\n", Problem_5(1, 20));
#define MODULE_1_EXTRA printf("Euler function(%d)=%d\n", 81, euler_fun(81)); \
	printf("Taylor e^2=%Lf\n", e_taylor(1., 0.001));
#define MY_STR_FUN char str[24]="Hello Word!"; \
	char str2[13]=" Hehehe hoho"; \
	char str3[5]="Word"; \
	printf("strlen %u\n", my_strlen(str)); \
	printf("   cat \"%s\"\n", my_strcat(str, str2)); \
	printf("   cmp \"%s\" \"%s\" %d\n", str, str2, my_strcmp(str, str2)); \
	printf("   str \"%s\" \"%s\" \"%s\"\n", str2, str3, my_strstr(str2, str3)); \
	printf("   cpy \"%s\" \"%s\" \"%s\"\n", str, str3, my_strcpy(str, str3)); \
	\
	FILE* f=fopen("Source code/cows and bulls.c", "r"); \
	char line[101]; \
	unsigned int i=0; \
	while(i<100) \
	{ \
		line[i]=' '; \
		i+=1; \
	} \
	line[i]='\0'; \
	printf("symbols=%u", my_fgetline(line, f)); \
	fclose(f); \
	printf(" \"%s\"\n", line);
#define MODULE_2 char str4[9]="abcdefgh"; \
	printf("\"%s\" ", str4); \
	chg_by_pair_sym(str4); \
	printf("\"%s\"\n", str4);

int main()
{
	EULER_PROJECT
	MODULE_1_EXTRA
	MY_STR_FUN
	MODULE_2
//Быки и коровы
	start_game(4);
	return 0;
}