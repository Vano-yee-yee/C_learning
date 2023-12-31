#pragma once
#include <time.h>
#include <stdio.h>

struct car
{
	char mark[100]; //char* mark;
	char manufacture[100]; //char* manufacture;
	unsigned short lift_weight;
	unsigned short year;
	struct tm regist_date;
};

/**
* @brief Инициализация данных о машинах с файла
* @param res_: результат - список машин
* @param file_: файл для чтения
* @param max_: максимальное количество считываемых машин
* @return ничего
*/
void insert(struct car* res_, const FILE* file_, const unsigned int max_);

/**
* @brief Запрос на машины, зарегистрированные более года назад и имеющие грузоподъёмность более 3-ёх тонн
* @param res_: результат - список машин
* @param db_: список машин
* @param amount_: количество машин
*/
void query1(struct car* res_, const struct car* db_, const unsigned int amount_);