#include "euler.h"
#include "functions.h"
#include "cows and bulls.h"
#include "str_func.h"
#include <stdio.h>

int main()
{
	printf("Task 1 %u\n", Problem_1(1000, (char[]){3, 5}, 2));
	printf("Task 2 %u\n", Problem_2(4000000));
	printf("Task 3 %llu\n", Problem_3(600851475143));
	printf("Task 4 %u\n", Problem_4(100, 999));
	printf("Task 5 %u\n", Problem_5(1, 20));

	char str[24]="Hello Word!";
	char str2[13]=" Hehehe hoho";
	char str3[5]="Word";
	printf("strlen %u\n", my_strlen(str));
	printf("   cat \"%s\"\n", my_strcat(str, str2));
	printf("   cmp \"%s\" \"%s\" %d\n", str, str2, my_strcmp(str, str2));
	printf("   str \"%s\" \"%s\" \"%s\"\n", str2, str3, my_strstr(str2, str3));
	printf("   cpy \"%s\" \"%s\" \"%s\"\n", str, str3, my_strcpy(str, str3));

	printf("Euler function(%d)=%d\n", 81, euler_fun(81));
	printf("Taylor e^2=%Lf\n", e_taylor(1., 0.001));
	start_game(4);
	return 0;
}