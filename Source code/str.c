#include "str.h"

unsigned int my_strlen(const char* str_)
{
	unsigned int len=0;
	while(*str_!='\0')
	{
		len+=1;
		str_+=1;
	}
	return len;
}
char* my_strcat(char* dest_, const char* source_)
{
	unsigned int source_len=my_strlen(source_);
	unsigned int dest_len=my_strlen(dest_);
	dest_+=dest_len;
	while(*source_!='\0')
	{
		*dest_=*source_;
		source_+=1;
		dest_+=1;
	}
	*dest_='\0';
	dest_-=source_len;
	dest_-=dest_len;
	return dest_;
}
int my_strcmp(const char* str1_, const char* str2_)
{
	unsigned int i=0;
	while(*str1_==*str2_
		&& (*str1_!='\0'
			|| *str2_!='\0'))
	{
		str1_+=1;
		str2_+=1;
		i+=1;
	}
	return *str1_-*str2_;
}
char* my_strstr(const char* str1_, const char* sub_str_)
{	
	unsigned int i=0;
	while(*sub_str_!='\0'
		&& *str1_!='\0')
	{
		if(*str1_==*sub_str_)
		{
			i+=1;
			sub_str_+=1;
			str1_+=1;
		}
		else
		{
			sub_str_-=i;
			str1_-=i;
			i=0;
			str1_+=1;
		}
	}
	sub_str_-=i;
	if(i<my_strlen(sub_str_))
		return NULL;
	str1_-=i;
	return (char*)str1_;
}
char* my_strcpy(char* dest_, const char* copy_)
{
	unsigned int i=0;
	while(*copy_!='\0')
	{
		*dest_=*copy_;
		dest_+=1;
		copy_+=1;
		i+=1;
	}
	dest_-=i;
	return dest_;
}
unsigned int my_fgetline(char* line_, const FILE* file_)
{
	unsigned int i=0;
	while(*line_!='\0'
		&& (*line_=fgetc(file_))!='\n')
	{
		line_+=1;
		i+=1;
	}
	*line_='\0';
	return i;
}
void chg_by_pair(char* str_)
{
	while(*str_!='\0'
		&& *(str_+1)!='\0')
	{
		char buf=*str_;
		*str_=*(str_+1);
		*(str_+1)=buf;
		str_+=2;
	}
}