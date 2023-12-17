#pragma once

/**
* @brief Загадывает число с различными цифрами
* @param dig_: количество цифр в числе [1, 10]
* @param res_: массив результат
* @return ничего
*/
void make_guess_num(unsigned char* res_, const unsigned char dig_);

/**
* @brief Прверяет число, полученное с потока ввода
* @param num_: число строка
* @param dig_: количество цифр в числе
* @return 1: число с данным кол-ом цифр
* 0: иначе
*/
unsigned char check_num(const unsigned char* num_, const unsigned char dig_);

/**
* @brief Начинает игру "Быки и коровы"
* @param dig_: количество цифр в числе [1, 10]
* @return ничего
*/
void start_game(const unsigned char dig_);