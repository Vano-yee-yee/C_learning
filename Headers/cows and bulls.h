#pragma once

/**
* @brief Загадывает число с различными цифрами
* @param dig_: количество цифр в числе [1, 10]
* @param res_: массив результат
* @return ничего
*/
void make_guess_num(unsigned char* res_, const unsigned char dig_);

/**
* @brief Превращает символ цифры в число
* @param c: символ
* @return число
*/
unsigned char char_to_digit(unsigned char c);

/**
* @brief Начинает игру "Быки и коровы"
* @param dig_: количество цифр в числе [1, 10]
* @return ничего
*/
void start_game(const unsigned char dig_);