#include <functions.h>

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