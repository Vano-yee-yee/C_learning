#if !defined(EULER_H)#define EULER_H/*** @brief Находит сумму чисел, кратных числам* @param lim_: верхняя граница поиска* @param div_: делители кратности* @param div_n_: количество делителей* @return число*/unsigned short Problem_1(unsigned short lim_, const unsigned char* div_, unsigned char div_n_);/*** @brief Находит сумму чётных элементов ряда Фибоначи* @param lim_: верхняя граница поиска* @return число*/unsigned int Problem_2(unsigned int lim_);/*** @brief Находит наибольший простой делитель числа* @param num_: число, в котором ищется делитель* @return -1: num_=0* число: иначе*/long long Problem_3(long long num_);/*** @brief Находит наибольший палиндром, полученный произведением 2-ух чисел* @param min_lim_: минимальное число поиска* @param max_lim_: максимальное число поиска* @return число*/unsigned int Problem_4(unsigned short min_lim_, unsigned short max_lim_);/*** @brief Находит наименьшее число, которое кратно числам* @param div_min_: минимальное кратное число* @param div_max_: максимальное кратное число* @return число*/unsigned int Problem_5(unsigned char div_min_, unsigned char div_max_);/*** @brief Находит разность между суммой квадратов и квадратом суммы чисел* @param first_num_: левая граница* @param last_num: правая граница* @return число*/int Problem_6(unsigned char first_num_, unsigned char last_num_);/*** @brief Находит простое число* @param sequence_num_: По счёту число* @return число*/unsigned int Problem_7(unsigned short sequence_num_);#endif