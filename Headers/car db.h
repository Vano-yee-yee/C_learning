#pragma once
#include <time.h>
#include <stdio.h>

struct car
{
	char mark[101]; //char* mark;
	char manufacture[101]; //char* manufacture;
	unsigned short lift_weight;
	unsigned short year;
	struct tm regist_date;
};

/**
* @brief Вывод в стандартный поток вывода информации о машине
* @param db_: список машин
* @param amount_: количество машин
* @return ничего
*/
void print(struct car* restrict db_, const unsigned int amount_);

/**
* @brief Инициализация данных о машинах с файла
* @param file_: файл для чтения
* @param max_: максимальное количество считываемых машин
* @return список машин
*/
struct car* insert(FILE* restrict file_, const unsigned int max_);

/**
* @brief Запрос на машины, зарегистрированные более года назад и имеющие грузоподъёмность более 3-ёх тонн
* @param db_: список машин
* @param amount_: количество машин
* @return список машин
*/
struct car* query1(struct car* restrict db_, const unsigned int amount_);