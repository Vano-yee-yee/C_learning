#pragma once

/**
* @brief Ќаходит сумму чисел, кратных числам
* @param lim_: верхн€€ граница поиска
* @param div_: делители кратности
* @return число
*/
unsigned short Problem_1(const unsigned short lim_, const unsigned char* div_, const unsigned char div_n_);

/**
* @brief Ќаходит сумму чЄтных элементов р€да ‘ибоначи
* @param lim_: верхн€€ граница поиска
* @return число
*/
unsigned int Problem_2(const unsigned int lim_);

/**
* @brief Ќаходит наибольший простой делитель числа
* @param num_: число, в котором ищетс€ делитель
* @return -1, если num_=0
* число, иначе
*/
unsigned long long Problem_3(long long num_);

/**
* @brief Ќаходит наибольший палиндром, полученный произведением 2-ух чисел
* @param min_lim_: минимальное число поиска
* @param max_lim_: максимальное число поиска
* @return число
*/
unsigned int Problem_4(const unsigned short min_lim_, unsigned short max_lim_);

/**
* @brief Ќаходит наименьшее число, которое кратно числам
* @param div_min_: минимальное кратное число
* @param div_max_: максимальное кратное число
* @return число
*/
unsigned int Problem_5(const unsigned char div_min_, const unsigned char div_max_);