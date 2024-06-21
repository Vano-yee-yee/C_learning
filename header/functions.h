#if !defined(FUNCTIONS_H)
#define FUNCTIONS_H

/**
* @brief Возвращает число в обратном порядке
* @param num_: число, из которого нужно получить в обратном порядке
* @return число
*/
unsigned int get_reverse_int(unsigned int num_);

/**
* @brief Определяет простоту числа
* @param num_: число
* @return 1: простое
* 0: иначе
*/
unsigned char is_simple_num(unsigned int num_);

/**
* @brief Вычисляет значение функции Эйлера
* @param x_: аргумент
* @return -1: значение не определено
* число: иначе
*/
int euler_fun(unsigned int x_);

/**
* @brief Разложение e^x в ряд Тейлора
* @param x_: аргумент
* @param prec_: точность
* @return действительное число
*/
long double e_taylor(long double x_, long double prec_);

/**
* @brief Превращает символ цифры в число
* @param c_: символ
* @return число: символ является цифрой
* 10: иначе
*/
unsigned char char_to_digit(char c_);
#endif