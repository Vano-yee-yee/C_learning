#include <euler.h>
#include <functions.h>

unsigned short Problem_1(const unsigned short lim_, const unsigned char* div_, const unsigned char div_n_)
{
	unsigned short current=0,
		sum=0;
	while(current<lim_)
	{
		unsigned char i=0;
		while(i<div_n_)
		{
			if(current%div_[i]==0)
			{
				sum+=current;
				i=div_n_;
			}
			i+=1;
		}
		current+=1;
	}
	return sum;
}
unsigned int Problem_2(const unsigned int lim_)
{
	unsigned int sum=0;
	unsigned int prev=1;
	unsigned int current=2;
	while(current<lim_)
	{
		if(current%2==0)
			sum+=current;
		current=current+prev;
		prev=current-prev;
	}
	return sum;
}
long long Problem_3(long long num_)
{
	unsigned long long i=2;
	if(num_==0)
		return -1;
	if(num_>-4
		&& num_<4)
		return num_;
	while(i<num_)
	{
		if(num_%i==0)
			num_/=i;
		else
			i+=1;
	}
	return num_;
}
unsigned int Problem_4(const unsigned short min_lim_, unsigned short max_lim_)
{
	unsigned int max=0;
	while(max_lim_>min_lim_-1)
	{
		unsigned short prev=max_lim_;
		while(prev>min_lim_-1)
		{
			unsigned int buf=prev*max_lim_;
			if(buf==get_reverse_int(buf)
				&& buf>max)
				max=buf;
			prev-=1;
		}
		max_lim_-=1;
	}
	return max;
}
unsigned int Problem_5(const unsigned char div_min_, const unsigned char div_max_)
{
	unsigned int min=div_max_;
	unsigned char div=div_min_;
	while(div<div_max_+1)
	{
		if(min%div==0)
			div+=1;
		else
		{
			min+=1;
			div=div_min_;
		}
	}
	return min;
}
int Problem_6(unsigned char first_num_, const unsigned char last_num_)
{
	unsigned int sum_of_sq = 0;
	unsigned int sum = 0;
	while(first_num_ < last_num_ + 1)
	{
		sum_of_sq += first_num_ * first_num_;
		sum += first_num_;
		first_num_ += 1;
	}
	return sum_of_sq - sum * sum;
}
unsigned int Problem_7(const unsigned short sequence_num_)
{
	unsigned short i = 0;
	unsigned int buf = 1;
	while (i < sequence_num_)
	{
		buf += 1;
		if (is_simple_num(buf))
			i += 1;
	}
	return buf;
}