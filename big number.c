#include "big number.h"
#include <stdlib.h>

struct Big_num
{
	size_t size;
	unsigned char is_negative;
	unsigned char* digits;
};

Big_num* create_BN(const char* str_)
{
	const unsigned int str_len = strlen(str_);
	if (str_len == 0
		|| str_ == NULL
		|| !is_str_int(str_))
		return NULL;
	Big_num* res = (Big_num*)malloc(sizeof(Big_num));
	if (res == NULL)
		return NULL;

	(*res).size = str_len;
	(*res).is_negative = (str_=='-');
	if ((*res).is_negative)
	{
		str_ += 1;
		(*res).size -= 1;
	}

	(*res).digits = (unsigned char*)malloc((*res).size*sizeof(unsigned char));
	if ((*res).digits == NULL)
	{
		free(res);
		return NULL;
	}
	size_t i = 0;
	while (i < (*res).size)
	{
		(*res).digits[i] = str_[i] - '0';
		i += 1;
	}
	return res;
}
void delete_BN(Big_num** bn_)
{
	free((*bn_)->digits);
	free(*bn_);

	*bn_ = NULL;
}
void print_BN(FILE* stream_, Big_num* bn_)
{
	if (bn_ == NULL)
	{
		fprintf(stream_, "Big_num is empty!\n");
		return;
	}

	if (bn_->is_negative)
		printf("-");

	for (size_t i = 0; i < bn_->size; ++i)
		fprintf(stream_, "%u", bn_->digits[i]);
	fprintf(stream_, "\n");
}
Big_num* adding(const Big_num* bn1_, const Big_num* bn2_)
{
	Big_num* res = (Big_num*)malloc(sizeof(Big_num));
	if (res == NULL)
		return NULL;

	unsigned char bigger;
	unsigned int diff;
	if ((*bn1_).size > (*bn2_).size)
	{
		(*res).size = (*bn1_).size + 1;
		bigger = 1;
		diff = (*bn1_).size - (*bn2_).size;
	}
	else
	{
		(*res).size = (*bn2_).size + 1;
		bigger = 2;
		diff = (*bn2_).size - (*bn1_).size;
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
			(*res).digits[i] = (*bn1_).digits[i - diff];
			break;
		case 2:
			(*res).digits[i] = (*bn2_).digits[i - diff];
			break;
		}
		i -= 1;
	}
	return res;
}