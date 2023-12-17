#include "cows and bulls.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

void make_guess_num(unsigned char* res_, const unsigned char dig_)
{
	srand(time(NULL));
	unsigned char i=0;
	unsigned char used_dig[10]={0};
	while(i<dig_)
	{
		if(!i)
			*res_=rand()%9+1;
		else
			*res_=rand()%10;
		if(!used_dig[*res_])
		{
			used_dig[*res_]=1;
			i+=1;
			res_+=1;
		}
	}
}
unsigned char char_to_digit(unsigned char c)
{
//For standart encoding(s)
//	return c-'0';

//For other encodings
	switch(c)
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
		default:
			return 10;
	}
}
void start_game(const unsigned char dig_)
{
	if(dig_>10 || dig_==0)
		return;
	unsigned char guess_num[dig_];
	make_guess_num(guess_num, dig_);
	printf("Computer make a number with %u digits. Try to guess\n", dig_);

	while(1)
	{
		unsigned char num[dig_];
		scanf("%s", num);

		unsigned char bulls=0;
		unsigned char cows=0;

		unsigned char i=0;
		while(i<dig_)
		{
			num[i]=char_to_digit(num[i]);
			if(num[i]>9)
			{
				printf("This is not a %d-digit number\n", dig_);
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
		printf("Bulls=%u, cows=%u\n", bulls, cows);
		if(bulls==dig_ && cows==0)
			return;
	}
}