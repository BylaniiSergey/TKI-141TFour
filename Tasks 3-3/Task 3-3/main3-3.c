#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <stdbool.h>
#include <locale.h>

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
double get_step(const char* message);

/**
 * @brief Функция возвращающая значение функции в данной точке
 * @param x - точка
 * @return Значение функции в точке x
 */
double function_1(double x);

/**
 * @brief Функция возвращающая значение суммы ряда в этой точке
 * @param x - точка
 * @param a - точка начала
 * @return Возвращает sum
 */
double summ(double a, double e);

/**
 * @brief Функция возвращающая значение функции в данной точке
 * @param x - точка
 * @param i - точка
 * @return Значение функции в точке x и i
 */
double function_2(double x, double i);

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
double get_value(const char* message);

/**
 * @brief Функция проверяет что b>a
 * @param a - точка
 * @param b - точка
 * @return Возвращает true если b>a, иначе false
 */
bool checkvars(double a, double b);

/**
 * @brief Функция проверяет шаг
 * @param step - шаг
 * @return Возвращает true если шаг больше 0, иначе false
 */
bool checkstep(double step);

/**
 * @brief Функция проверяет e
 * @param e - число
 * @return Возвращает true если e больше 0, иначе false
 */
bool checke(double x, double e);

/**
 * @brief Область определения функции
 * @param x - точка
 * @return Возвращает true если x принадлежит ООФ, иначе false
 */
bool OOF(double x);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "RU");

	double a = get_value("Введите(a) : ");
	double b = get_value("Введите(b) : ");
	double e = get_value("Введите(e) : ");
	checke(a, e);
	checkvars(a, b);
	double step = get_step("Введите(step): ");
	checkstep(step);
	for (double x = a; x - b <= DBL_EPSILON; x += step)
	{
		if (OOF(x))
		{
			printf_s("%lf\t%lf\t%lf\t\n", x, function_1(x), summ(x,e));
		}
		else
		{
			printf_s("При x, равном %d нет решения\n", x);
		}
	}
	return 0;
}

double function_1(double x)
{
	return (0.25) * log((1 + x) / (1 - x)) + (0.5) * atan(x);
}

double summ(double x, double e)
{
	double sum = 0;
	double s_i = function_2(x, 1);
	sum += 0;
	for (int i = 0; fabs(function_1(x) - sum) <= e + DBL_EPSILON; i++)
	{
		s_i += function_2(x, i);
		sum += s_i;
	}
	return sum;
}

double function_2(double x, double i)
{
	return (4 * i * pow(x, 4) + pow(x, 4)) / (4 * i + 5);
}

double get_step(const char* message)
{
	double a;
	printf_s("%s", message);
	int res = scanf_s("%lf", &a);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return a;
}

double get_value(const char* message)
{
	double value;
	printf_s("%s", message);
	int res = scanf_s("%lf", &value);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return value;
}

bool checkvars(double a, double b)
{
	if (a - b >= -DBL_EPSILON)
	{
		return false;
	}
	return true;
}

bool checkstep(double step)
{
	if (step <= DBL_EPSILON)
	{
		return false;
	}
	return true;
}

bool OOF(double x)
{
	if (fabs(x - 1) <= DBL_EPSILON || ((1 + x) / (1 - x)) <= DBL_EPSILON)
	{
		return false;
	}
	return true;
}

bool checke(double a, double e)
{
	if (e<=DBL_EPSILON || e>=fabs(a) )
	{
		return false;
	}
	return true;
}