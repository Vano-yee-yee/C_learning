#pragma once

/**
* @brief Преобразует цифры дестятичной записи числа в массив
* @param num_: число для преобразования
* @param res_: массив результат
*/
//void int_to_array10(unsigned int num_, unsigned char* res_, const unsigned char dig_);

/**
* @brief Загадывает число с различными цифрами
* @param dig_: количество цифр в числе [1, 10]
* @param res_: массив результат
*/
void make_guess_num(unsigned char* res_, const unsigned char dig_);

/**
* @brief Начинает игру "Быки и коровы"
* @param dig_: количество цифр в числе [1, 10]
*/
void start_game(const unsigned char dig_);