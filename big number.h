#pragma once
#include <stdio.h>

typedef struct Big_num Big_num;

/**
* @brief Создаёт большое число из строки
* @param str_: строка число
* @return большое число
*/
Big_num* create_BN(const char* str_);

/**
* @brief
* @param
* @return
*/
void delete_BN(Big_num** bn_);

/**
* @brief
* @param
* @return
*/
void print_BN(FILE* stream_, Big_num* bn_);

/**
* @brief 
* @param 
* @return 
*/
Big_num* adding(const Big_num* bn1_, const Big_num* bn2_);

/**
* @brief 
* @param 
* @return 
*/
Big_num* subtraction(const Big_num* bn1_, const Big_num* bn2_);

/**
* @brief 
* @param 
* @return 
*/
Big_num* multiplication(const Big_num* bn1_, const Big_num* bn2_);

/**
* @brief 
* @param 
* @return 
*/
Big_num* division(const Big_num* bn1_, const Big_num* bn2_);