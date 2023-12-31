#pragma once

/**
* @brief Находит сумму чисел, кратных числам
* @param lim_: верхняя граница поиска
* @param div_: делители кратности
* @param div_n_: количество делителей
* @return число
*/
unsigned short Problem_1(const unsigned short lim_, const unsigned char* div_, const unsigned char div_n_);

/**
* @brief Находит сумму чётных элементов ряда Фибоначи
* @param lim_: верхняя граница поиска
* @return число
*/
unsigned int Problem_2(const unsigned int lim_);

/**
* @brief Находит наибольший простой делитель числа
* @param num_: число, в котором ищется делитель
* @return -1: num_=0
* число: иначе
*/
unsigned long long Problem_3(long long num_);

/**
* @brief Находит наибольший палиндром, полученный произведением 2-ух чисел
* @param min_lim_: минимальное число поиска
* @param max_lim_: максимальное число поиска
* @return число
*/
unsigned int Problem_4(const unsigned short min_lim_, unsigned short max_lim_);

/**
* @brief Находит наименьшее число, которое кратно числам
* @param div_min_: минимальное кратное число
* @param div_max_: максимальное кратное число
* @return число
*/
unsigned int Problem_5(const unsigned char div_min_, const unsigned char div_max_);