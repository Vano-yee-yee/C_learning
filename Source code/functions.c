#include "functions.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

unsigned int get_reverse_int(unsigned int num_)
{
	unsigned int rev=0;
	while(num_>0)
	{
		rev=rev*10+num_%10;
		num_/=10;
	}
	return rev;
}
unsigned char is_simple_num(const unsigned int num_)
{
	if(num_==1)
		return 0;
	unsigned int i=2;
	while(i<num_)
	{
		if(num_%i==0)
			return 0;
		i+=1;
	}
	return 1;
}
int euler_fun(const unsigned int x_)
{
	if(x_==0)
		return -1;
	if(is_simple_num(x_))
		return x_-1;
	unsigned int count=1;
	unsigned int current=2;
	unsigned int i=2;
	while(current<x_)
	{
		if(current%i==0
			&& x_%i==0)
		{
			current+=1;
			i=2;
		}
		else
			i+=1;
		if(i>current)
		{
			count+=1;
			current+=1;
			i=2;
		}
	}
	return count;
}
long double e_taylor(const long double x_, const long double prec_)
{
	long double p=1.;
	int res=1/prec_;
	unsigned int i=1;
	while(p!=0.)
	{
		p*=x_/i;
		res+=p/prec_;
		i+=1;
	}
	return res*prec_;
}
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
unsigned char char_to_digit(const char c_)
{
//For standart encoding(s)
//	return c_-'0';
//For other encodings
	switch(c_)
	{
		case '0':
			return 0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
	}
//Change
	return 10;
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