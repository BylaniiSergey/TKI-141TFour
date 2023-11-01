#include <math.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>
#include <stdio.h>

/**
 * @brief Функция расчитывающая значение y при x < 2.
 * @param x Входная величина.
 * @param a Входная величина.
 * @return Значение функции.
 */
double get_y_1(double x);

/**
 * @brief Функция расчитывающая значение y при x >= 2.
 * @param x Входная величина.
 * @param a Входная величина.
 * @return Значение функции.
 */
double get_y_2(double x);

/**
 * @brief Функция принимающая и проверяющая значение на ввод.
 * @return Значение.
 */
double get_value();

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
    double x;
    const double a = 2.3;
    puts("Enter x: ");
    x = get_value();
    double result = 0;
    if (x < 2)
    {
        result = get_y_1(x);
    }
    else if (x >= 2)
    {
        result = get_y_2(x);
    }
    else
    {
        errno = EIO;
        perror("Wrong value");
        return 1;
    }
    printf("%lf", "Результат: ", result);
    return 0;
}
double get_y_1(double x)
{
    double y = 1.5 * (cos(x) * cos(x));
    return y;
}
double get_y_2(double x)
{
    double y = ((x - 2) * (x - 2)) + 6;
    return y;
}
double get_value()
{
    double a;
    int res = scanf_s("%lf", &a);
    if (res != 1)
    {
        errno = EIO;
        perror("Wrong value");
        abort();
    }
    return a;
}