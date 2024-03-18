#pragma once
#include <stdio.h>

typedef struct Time
{
	unsigned char day;
	unsigned char month;
	unsigned short year;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
} Time;

/**
* @brief Определяет високосный ли год
* @param year_: год
* @return 1: високосный год
* 0: иначе
*/
unsigned char is_leap_year(const short year_);

/**
* @brief Находит разницу во времени
* @param time1_: время 1-ое
* @param time2_: время 2-ое
* @return время
*/
Time* diff_time(const Time* time1_, const Time* time2_);

/**
* @brief Выводит информацию о времи в формате d.m.y h:mi:s
* @param stream_: поток для вывода
* @param time_: время
* @return ничего
*/
void print_time(FILE* restrict stream_, const Time* time_);