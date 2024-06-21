#if !defined(CAR_DATABASE_H)
#define CAR_DATABASE_H
#include <stdio.h>

typedef struct Car Car;

/**
* @brief Вывод в информации о машине
* @param stream_: поток для вывода
* @param db_: список машин
* @param amount_: количество машин
*/
void print_car(FILE* restrict stream_, const Car* db_, unsigned int amount_);

/**
* @brief Инициализация данных о машинах с файла, их количество записывается в amount_
* @param file_: файл для чтения
* @param amount_: количество считанных машин
* @return список машин
*/
Car* insert_car(FILE* restrict file_, unsigned int* restrict amount_);

/**
* @brief Запрос на машины, зарегистрированные более года назад и имеющие грузоподъёмность более 3-ёх тонн
* @param db_: список машин
* @param amount_: количество машин
* @param new_amount_: количество машин запроса (вычисляемое)
* @return список машин
*/
Car* query_car(const Car* db_, unsigned int amount_, unsigned int* restrict new_amount_);
#endif