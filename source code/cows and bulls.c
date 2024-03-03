#include <cows and bulls.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "functions.h"

unsigned char* make_guess_num(const unsigned char dig_)
{
	if(dig_>10
		|| dig_==0)
		return NULL;
	srand(time(NULL));
	unsigned char used_dig[10]={0};
	unsigned char* res=(unsigned char*)realloc(NULL, dig_*sizeof(char));
	unsigned char i=0;
	while(i<dig_)
	{
		if(!i)
			*res=rand()%9+1;
		else
			*res=rand()%10;
		if(!used_dig[*res])
		{
			used_dig[*res]=1;
			i+=1;
			res+=1;
		}
	}
	res-=i;
	return res;
}
void cows_and_bulls(const unsigned char dig_)
{
	if(dig_>10
		|| dig_==0)
		return;
	unsigned char* guess_num=make_guess_num(dig_);
	fprintf(stdout, "Computer make a number with %u different digits. Try to guess\n", dig_);
	while(1)
	{
		unsigned char num[dig_];
		fscanf(stdin, "%s", num);
		unsigned char bulls=0;
		unsigned char cows=0;
		unsigned char i=0;
		while(i<dig_)
		{
			num[i]=char_to_digit(num[i]);
			if(num[i]>9)
			{
				fprintf(stderr, "This is not a %d-digit number\n", dig_);
				break;
			}
			unsigned char j=0;
			while(j<dig_)
			{
				if(num[i]==guess_num[j])
				{
					if(i==j)
						bulls+=1;
					else
						cows+=1;
					break;
				}
				j+=1;
			}
			i+=1;
		}
		fprintf(stdout, "Bulls=%u, cows=%u\n", bulls, cows);
		if(bulls==dig_
			&& cows==0)
			return;
	}
}