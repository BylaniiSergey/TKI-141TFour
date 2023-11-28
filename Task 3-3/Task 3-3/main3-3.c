#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <locale.h>

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
 * @brief Функция возвращающая значение суммы ряда в этой точке.
 * @param x - точка.
 * @return Значение суммы ряда в точке x.
 */
double summ(double x, double e);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "RU");
	double a = get_value("Введите(a) : ");
	double x = a;
	double b = get_value("Введите(b) : ");
	double step = get_step("Enter step: ");
	double e = pow(30, -5);
	for (double i = a; i - b <= DBL_EPSILON; i += step)
	{
		printf("%lf\t%lf\t%lf\t\n", i, function(i), summ(i, e));
	}
	return 0;
}

double function(double x)
{
	return (1 / 4) * log((1 + x) / (1 - x)) + (1 / 2) * atan(x);
}

double get_s_i(double i, double x)
{
	return (4 * i * pow(x, 4) + pow(x, 4)) / (4 * i + 5);
}

double summ(double x)
{
	double sum = 0;
	sum += 0;
	for (int i = 0; function(x) - sum <= DBL_EPSILON; i++)
	{
		sum += get_s_i(i, x);
	}
	return sum;
}

double get_step(const char* message)
{
	double a;
	printf("%s", message);
	int res = scanf_s("%lf", &a);
	if (res != 1 || a <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return a;
}

double get_value(const char* message)
{
	double b;
	printf("%s", message);
	int res = scanf_s("%lf", &b);
	if (res != 1 || b <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return b;
}

void check_range(double a, double b)
{
	if (a > b)
	{
		errno = EIO;
		perror("ERROR");
		abort();
	}
}