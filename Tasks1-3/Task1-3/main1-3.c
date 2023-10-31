# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include <errno.h>


/**
* @brief Функция проверяет и принимает знпчения
* @return Значение
*/
double get_value_I();


/**
* @brief Функция проверяет и принимает знпчения
* @return Значение
*/
double get_value_U();


/**
* @brief Функция для нахождения работы в электродвигателе вентилятора
* @param I - сила тока в электродвигателе вентилятора
* @param t - время в электродвигателе вентилятора
* @param U - напряжение в электродвигателе вентилятора
* @return Работа в электродвигателе вентилятора
*/
double def_A(double I, double U, double t);


/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
	int res;
	setlocale(LC_ALL, "RU");
	double t = 1200.0;
	printf("Введите силу тока в электродвигателе вентилятора (I): ");
	double I;
	res = scanf_s("%lf", &I);
	printf("Введите напряжение в электродвигателе вентилятора (U): ");
	double U;
	res = scanf_s("%lf", &U);
	double A = def_A(I, U, t);
	printf("Работа в электродвигателе вентилятора: %lf", A);
	return 0;
}


double get_value_I()
{
	double I;
	int res = scanf_s("% lf", &I);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return I;
}


double get_value_U()
{
	double U;
	int res = scanf_s("% lf", &U);
	if (res != 1)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return U;
}


double def_A(double I, double U, double t)
{
	return (I * U * t);
}