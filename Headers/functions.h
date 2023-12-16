#pragma once

/**
* @brief Отдаёт число в обратном порядке
* @param num_: число, из которого нужно получить в обратном порядке
* @return число
*/
unsigned int get_reverse_int(unsigned int num_);

/**
* @brief Определяет простоту числа
* @param num_: число
* @return 1: простое
* 0: иначе
*/
unsigned char is_simple_num(unsigned int num_);

/**
* @brief Вычисляет значение функции Эйлера
* @param x_: аргумент
* @return -1, если значение не определено
* число, иначе
*/
int euler_fun(const unsigned int x_);

/**
* @brief Разложение e^x в ряд Тейлора
* @param x_: аргумент
* @param prec_: точность
* @return дробное число
*/
long double e_taylor(const long double x_, const long double prec_);