#include <stdio.h>
#include "euler.h"
#include "functions.h"
#include "cows and bulls.h"
#include "str_func.h"

#define EULER_PROJECT printf("Task 1 %u\n", Problem_1(1000, (char[]){3, 5}, 2)); \
	printf("Task 2 %u\n", Problem_2(4000000)); \
	printf("Task 3 %llu\n", Problem_3(600851475143)); \
	printf("Task 4 %u\n", Problem_4(100, 999)); \
	printf("Task 5 %u\n", Problem_5(1, 20));
#define MODULE_1 printf("Euler function(%d)=%d\n", 81, euler_fun(81)); \
	printf("Taylor e^2=%Lf\n", e_taylor(1., 0.001)); \
	start_game(4);
#define STRING_FUNCTIONS char str[24]="Hello Word!"; \
	char str2[13]=" Hehehe hoho"; \
	char str3[5]="Word"; \
	printf("%u\n", my_strlen(str)); \
	printf("%s\n", my_strcat(str, str2)); \
	printf("%d\n", my_strcmp(str, str2)); \
	printf("%s\n", my_strstr(str2, str3)); \
	printf("%s\n", my_strcpy(str, str3));

int main()
{
	MODULE_1
	return 0;
}