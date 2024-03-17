#include <big number.h>
#include <my string.h>
#include <functions.h>
#include <stdlib.h>

struct Big_num
{
	size_t size;
	unsigned char is_negative;
	unsigned char* digits;
};

Big_num* create_BN(const char* str_)
{
	const unsigned int len=my_strlen(str_);
	if(!(len
		&& is_str_int(str_)))
		return NULL;
	
	Big_num* res=(Big_num*)realloc(NULL, sizeof(Big_num));
	if(!res)
		return NULL;
	(*res).size=len;
	(*res).is_negative=((*str_)=='-');
	if((*res).is_negative)
	{
		str_+=1;
		(*res).size-=1;
	}

	(*res).digits=(unsigned char*)realloc(NULL, (*res).size*sizeof(unsigned char));
	if(!(*res).digits)
	{
		res=realloc(res, 0);
		return NULL;
	}
	size_t i=0;
	while(i<(*res).size)
	{
		(*res).digits[i]=char_to_digit(str_[i]);
		i+=1;
	}
	return res;
}
void delete_BN(Big_num* restrict num_)
{
	(*num_).digits=realloc((*num_).digits, 0);
	num_=realloc(num_, 0);
}
void print_BN(FILE* restrict stream_, const Big_num* num_)
{
	if(!(num_
		&& (*num_).digits))
	{
		fprintf(stream_, "empty\n");
		return;
	}
	if((*num_).is_negative)
		printf("-");
	size_t i=0;
	while(i<(*num_).size)
	{
		fprintf(stream_, "%u", (*num_).digits[i]);
		i+=1;
	}
}
Big_num* adding(const Big_num* num1_, const Big_num* num2_)
{
	Big_num* res=(Big_num*)malloc(sizeof(Big_num));
	if (res == NULL)
		return NULL;

	unsigned char bigger;
	unsigned int diff;
	if ((*num1_).size > (*num2_).size)
	{
		(*res).size = (*num1_).size + 1;
		bigger = 1;
		diff = (*num1_).size - (*num2_).size;
	}
	else
	{
		(*res).size = (*num2_).size + 1;
		bigger = 2;
		diff = (*num2_).size - (*num1_).size;
	}
	(*res).digits = (unsigned char*)calloc((*res).size, sizeof(unsigned char));
	if ((*res).digits == NULL)
	{
		free(res);
		return NULL;
	}

	size_t i = (*res).size;
	while (i > 1)
	{
		switch (bigger)
		{
		case 1:
			(*res).digits[i] = (*num1_).digits[i - diff];
			break;
		case 2:
			(*res).digits[i] = (*num2_).digits[i - diff];
			break;
		}
		i -= 1;
	}
	return res;
}