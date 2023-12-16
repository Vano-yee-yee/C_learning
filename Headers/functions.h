#pragma once

/**
* @brief ����� ����� � �������� �������
* @param num_: �����, �� �������� ����� �������� � �������� �������
* @return �����
*/
unsigned int get_reverse_int(unsigned int num_);

/**
* @brief ���������� �������� �����
* @param num_: �����
* @return 1: �������
* 0: �����
*/
unsigned char is_simple_num(unsigned int num_);

/**
* @brief ��������� �������� ������� ������
* @param x_: ��������
* @return -1, ���� �������� �� ����������
* �����, �����
*/
int euler_fun(const unsigned int x_);

/**
* @brief ���������� e^x � ��� �������
* @param x_: ��������
* @param prec_: ��������
* @return ������� �����
*/
long double e_taylor(const long double x_, const long double prec_);