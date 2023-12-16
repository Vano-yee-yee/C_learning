#pragma once
#include <stdio.h>

/**
* @brief ������� ����� ������
* @param str_: ������
* @return ����� ������
*/
unsigned int my_strlen(const char* str_);

/**
* @brief ������� �����
* @param dest_: ������, � ������� ����������� ������ source_
* @param source_: 2-�� ������
* @return ������������ �����
*/
char* my_strcat(char* dest_, const char* source_);

/**
* @brief ��������� �����
* @param str1_: ������ 1-��
* @param str2_: ������ 2-��
* @return 0: ������ �����
* ��������>0: ������ � str1_ ������ ������� � str2_ �� ����
* ��������<0: ������ � str1_ ������ ������� � str2_ �� ����
*/
int my_strcmp(const char* str1_, const char* str2_);

/**
* @brief ������� 1-�� ��������� ������
* @param str1_: ������ ������
* @param str2_: ���������
* @return ����� ������, ���� ��������� �������
* ������ ������, ��������� �� �������
*/
char* my_strstr(const char* str1_, const char* sub_str_);

/**
* @brief ���������� � ������ dest_ ������ ������ copy_
* @param dest_: ������, � ������� ������������ copy_
* @param copy: ������ ��� ������ � 1-��
* @return ������
*/
char* my_strcpy(char* dest_, const char* copy_);

/**
* @brief ��������� ������ � �����
* @param line_: ������, ���������� �����������
* @param file_: ���� ����������
* @return ����� �������� � ������
*/
int my_fgetline(char* line_, const FILE* file_);