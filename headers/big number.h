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
* @brief Удаляет большое число
* @param bn_: большое число
*/
void delete_BN(Big_num* restrict num_);

/**
* @brief Вывод большого числа
* @param stream_: поток вывода
* @param bn_: большое число
*/
void print_BN(FILE* restrict stream_, const Big_num* num_);

/**
* @brief Вычисляет сумму больших чисел
* @param bn1_: большое число 1
* @param bn2_: большое число 2
* @return большое число
*/
Big_num* adding(const Big_num* num1_, const Big_num* num2_);

/**
* @brief Вычисляет разность больших чисел
* @param bn1_: большое число 1
* @param bn2_: большое число 2
* @return большое число
*/
Big_num* subtraction(const Big_num* num1_, const Big_num* num2_);

/**
* @brief Вычисляет произведение больших чисел
* @param bn1_: большое число 1
* @param bn2_: большое число 2
* @return большое число
*/
Big_num* multiplication(const Big_num* num1_, const Big_num* num2_);

/**
* @brief Вычисляет частное больших чисел
* @param bn1_: большое число 1
* @param bn2_: большое число 2
* @return большое число
*/
Big_num* division(const Big_num* num1_, const Big_num* num2_);