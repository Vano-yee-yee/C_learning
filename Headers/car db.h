#pragma once
#include <time.h>
#include <stdio.h>

#define CAR_MARK_MAX 50
#define CAR_MARK_MAX_S "50"
#define CAR_MANUFACTURE_MAX 100
#define CAR_MANUFACTURE_MAX_S "100"

struct Car
{
	char mark[CAR_MARK_MAX+1];
	char manufacture[CAR_MANUFACTURE_MAX+1];
	unsigned short lift_weight;
	unsigned short year_manuf;
	time_t regist_date;
};

/**
* @brief Вывод в информации о машине
* @param stream_: поток для вывода
* @param db_: список машин
* @param amount_: количество машин
*/
void print_car(FILE* restrict stream_, const struct Car* db_, const unsigned int amount_);

/**
* @brief Инициализация данных о машинах с файла, их количество записывается в amount_
* @param file_: файл для чтения
* @param amount_: количество считанных машин
* @return список машин
*/
struct Car* insert_car(FILE* restrict file_, unsigned int* restrict amount_);

/**
* @brief Запрос на машины, зарегистрированные более года назад и имеющие грузоподъёмность более 3-ёх тонн
* @param db_: список машин
* @param amount_: количество машин
* @param new_amount_: количество машин запроса
* @return список машин
*/
struct Car* query_car(const struct Car* db_, const unsigned int amount_, unsigned int* restrict new_amount_);