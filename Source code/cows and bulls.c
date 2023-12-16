#include "cows and bulls.h"
#include "stdlib.h"
#include "stdio.h"
#include "time.h"

/*unsigned int dig10_count(unsigned int num_)
{
	unsigned int count=1;
	while((num_/=10)!=0)
		count+=1;
	return count;
}
void int_to_array10(unsigned int num_, unsigned char* res_, const unsigned char dig_)
{
	char i=dig_-1;
	while(i>-1)
	{
		res_[i]=num_%10;
		num_/=10;
		i-=1;
	}
}
*/
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
void start_game(const unsigned char dig_)
{
	if(dig_>10)
		return;
	unsigned char con=1;
	unsigned char guess_num[dig_];
	make_guess_num(guess_num, dig_);
	printf("Computer make a number with %d digits. Try to guess\n", dig_);
	while(con)
	{
		unsigned char num[dig_];
		unsigned char i=0;
		while(i<dig_ && scanf("%c", &num[i]))
		{
			num[i]-='0';
			i+=1;
		}
	}
}