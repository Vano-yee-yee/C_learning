#if !defined(MATRIX_H)
#define MATRIX_H

/**
* @brief Вычисляет определитель матрицы
* @param matrix_: квадратная матрица
* @param n_: порядок матрицы
* @return действительное число
*/
double determinant(const double* matrix_, unsigned int n_);

/**
* @brief Находит обратную матрицу
* @param matrix_: квадратная матрица (массив чисел)
* @param n_: порядок матрицы
* @return массив чисел
*/
double* reverse_matrix(const double* matrix_, unsigned int n_);

/**
* @brief Решает СЛУ методом Крамера
* @param coefficients_: коэффициенты при неизвестных и свободные члены
* @param unknowns_: количество неизвестных
* @return массив значений неизвестных (слева-направо)
*/
double* Kramer_LES(const double* coefficients_, unsigned int unknowns_);
#endif