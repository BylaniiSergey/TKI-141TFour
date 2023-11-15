#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>

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
double function(double x);

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
	double const a = 0.1;
	double x = a;
	double const b = 0.8;
	double step = get_step("Enter step: ");
	double e = pow(30, -5);
	for (double i = a; i - b <= DBL_MIN; i += step)
	{
		printf("%lf\t%lf\t%lf\t\n", i, function(i), summ(i, e));
	}
	return 0;
}

double function(double x)
{
	return (1/4)*log((1+x)/(1-x))+(1/2)*atan(x);
}

double summ(double x, double e)
{
	double sum = 0;
	int i = 1;
	double s_i = (x*(pow(x,5)/5) * i / (i + 1));
	sum += s_i;
	for (int i = 2; s_i > e; i++)
	{
		s_i += (x * (pow(x, 5) / 5) * i / (i + 1));
		sum += s_i;
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
