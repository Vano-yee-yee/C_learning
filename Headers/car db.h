#pragma once
#include <time.h>
#include <stdio.h>

struct car
{
	char* mark;
	char* manufacture;
	unsigned short lift_weight;
	unsigned short year;
	struct tm regist_date;
};

/**
* @brief Инициализация данных о машинах с файла
* @param file_: файл для чтения
* @return список машин
*/
struct car* insert(const FILE* file_);

/**
* @brief Запрос на машины, зарегистрированные более года назад и имеющие грузоподъёмность более 3-ёх тонн
* @param db_: список машин
* @param amount_: количество машин
* @return список машин
*/
struct car* query1(const struct car* db_, const unsigned short amount_);