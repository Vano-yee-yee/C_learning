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
* @return -1: значение не определено
* число: иначе
*/
int euler_fun(const unsigned int x_);

/**
* @brief Разложение e^x в ряд Тейлора
* @param x_: аргумент
* @param prec_: точность
* @return действительное число
*/
long double e_taylor(const long double x_, const long double prec_);

/**
* @brief Загадывает число с различными цифрами
* @param dig_: количество цифр в числе [1, 10]
* @return массив цифр
*/
unsigned char* make_guess_num(const unsigned char dig_);

/**
* @brief Превращает символ цифры в число
* @param c_: символ
* @return число
*/
unsigned char char_to_digit(const char c_);

/**
* @brief Начинает игру "Быки и коровы"
* @param dig_: количество цифр в числе [1, 10]
* @return ничего
*/
void cows_and_bulls(const unsigned char dig_);