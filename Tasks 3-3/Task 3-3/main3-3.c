#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <locale.h>
#include <stdbool.h>


/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
double get_step(const char* message);

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
double get_value(const char* message);

/**
 * @brief Функция возвращающая значение функции в данной точке
 * @param x - точка
 * @return Значение функции в точке x
 */
double function(double x);

/**
* @brief Функция для s_i
* @param i -  перменная
* @param x -  точка
* @return s_i
*/
double get_s_i(double i, double x);

/**
 * @brief Функция возвращающая значение суммы ряда в этой точке
 * @param x - точка
 * @return Значение суммы ряда в точке x
 */
double summ(double x);

/**
 * @brief Функция проверяющая что x_finish>x_start
 * @param x_start - число
 * @param x_finish - число
 */
void check_range(double x_start, double x_finish, double step);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "RU");
	double x_start = get_value("Введите(x_start) : ");
	double x_finish = get_value("Введите(x_finish) : ");
	double step = get_step("Enter step: ");
	check_range( x_start,  x_finish,  step);
	for (double x = x_start; x - x_finish <= DBL_EPSILON; x += step)
	{
		printf("%lf\t%lf\t%lf\t\n", x, function(x), summ(x));
	}
	return 0;
}

double function(double x)
{
	if (x != 1 && x < -1)
	{
		errno = EIO;
		perror("при этом x нет решений");
		abort();
	}
	return (0,25) * log((1 + x) / (1 - x)) + (0,5) * atan(x);
}

double get_s_i(double i, double x)
{
	return (4 * i * pow(x, 4) + pow(x, 4)) / (4 * i + 5);
}

double summ(double x)
{
	double sum = 0;
	sum += 0;
	for (int i = 0; fabs(function(x) - sum) <= DBL_EPSILON; i++)
	{
		sum += get_s_i(i, x);
	}
	return sum;
}

double get_step(const char* message)
{
	double x_start;
	printf("%s", message);
	int res = scanf_s("%lf", &x_start);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return x_start;
}

double get_value(const char* message)
{
	double x_finish;
	printf("%s", message);
	int res = scanf_s("%lf", &x_finish);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return x_finish;
}

void check_range(double x_start, double x_finish, double step)
{
	if ((x_start > x_finish - DBL_EPSILON) && step > 0)
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
}