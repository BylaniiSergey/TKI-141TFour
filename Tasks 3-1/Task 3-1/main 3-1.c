#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <stdbool.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief Функция для проверки Y на существование.
* @return Возвращает true, если Y существует, иначе false.
*/
bool is_exist(double x);

/**
* @brief Функция для подсчёта Y.
* @return Y.
*/
double get_Y(double x);

/**
* @brief Получает целое значение
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return Целое значение
*/
int main()
{
    const double x_start = 1.0;
    const double x_finish = 2.0;
    const double step = 0.1;
    double x = x_start;

    while (x <= x_finish)
    {
        if (is_exist(x))
        {
            double y = get_Y(x);
            printf_s("%lf %lf\n", x, y);
        }
        else
        {
            printf_s("%lf Нет решения\n", x);

        }
        x += step;
    }

    return EXIT_SUCCESS;
}

bool is_exist(double x)
{
    return (abs(x)>= DBL_MIN);
}

double get_Y(double x)
{
    return ((cos(2 / x)) - 2 * sin(1 / x) + (1 / x));
}