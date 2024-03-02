#pragma once

typedef struct Big_num
{
  size_t size;
  unsigned char is_negative;
  unsigned char digits;
} Big_num;

/**
* @brief 
* @param 
* @return 
*/
Big_num* create_from_str(const char* str_);

/**
* @brief 
* @param 
* @return 
*/
Big_num* adding(const Big_num*, const Big_num);

/**
* @brief 
* @param 
* @return 
*/
Big_num* subtraction(const Big_num*, const Big_num);

/**
* @brief 
* @param 
* @return 
*/
Big_num* multiplication(const Big_num*, const Big_num);

/**
* @brief 
* @param 
* @return 
*/
Big_num* division(const Big_num*, const Big_num);
