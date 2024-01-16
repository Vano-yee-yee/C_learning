#pragma once
#include <stdio.h>

/**
* @brief Находит длину строки
* @param str_: строка
* @return длину строки
*/
unsigned int my_strlen(const char* str_);

/**
* @brief Слияние строк
* @param dest_: строка, к которой добавляется строка source_
* @param source_: 2-ая строка
* @return конкатенацию строк
*/
char* my_strcat(char* dest_, const char* source_);

/**
* @brief Сравнение строк
* @param str1_: строка 1-ая
* @param str2_: строка 2-ая
* @return 0: строки равны
* значение>0: символ в str1_ больше символа в str2_ по коду
* значение<0: символ в str1_ меньше символа в str2_ по коду
*/
int my_strcmp(const char* str1_, const char* str2_);

/**
* @brief Находит 1-ое вхождение строки
* @param str1_: строка поиска
* @param sub_str_: подстрока
* @return строку: вхождение найдено
* пустую строку: вхождение не найдено
*/
char* my_strstr(const char* str1_, const char* sub_str_);

/**
* @brief Записывает в строку dest_ другую строку
* @param dest_: строка, к которой записывается
* @param copy_: строка для записи в 1-ую
* @return строку
*/
char* my_strcpy(char* dest_, const char* copy_);

/**
* @brief Считывает строку в файле
* @param line_: строка, получаемая считыванием
* @param file_: файл считывания
* @return число символов в строке
*/
unsigned int my_fgetline(char* line_, FILE* restrict file_);

/**
* @brief Заменяет рядом стоящие символы между собой
* @param str_: строка
* @return ничего
*/
void chg_by_pair(char* str_);