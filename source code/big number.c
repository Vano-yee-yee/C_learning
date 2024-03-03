#include <big number.h>
#include <stddef.h>

struct Big_num
{
	size_t size;
	unsigned char is_negative;
	unsigned char digits;
};