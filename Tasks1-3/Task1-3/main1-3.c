# include <stdio.h>
# include <locale.h>
# include <stdlib.h>


/**
* @brief Функция для проверки ввода сил тока
* @param res - количесвто аргументов
*/
void def_I(int res);


/**
* @brief Функция для проверки ввода напряжения
* @param res - количесвто аргументов
*/
void def_U(int res);


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
* @return 0 в случае успеха
*/
int main()
{
	int res;
	setlocale(LC_ALL, "RU");
	double t = 1200.0;
	printf("Введите силу тока в электродвигателе вентилятора (I): ");
	double I;
	res = scanf_s("%lf", &I);
	def_I(res);
	printf("Введите напряжение в электродвигателе вентилятора (U): ");
	double U;
	res = scanf_s("%lf", &U);
	def_I(res);
	double A = def_A(I, U, t);
	printf("Работа в электродвигателе вентилятора: %lf", A);
	return 0;
}


void def_I(res)
{
	if (res != 1)
	{
		printf("%s", "Введено неверное значение");
		abort();
	}
}


void def_U(res)
{
	double U;
	if (res != 1)
	{
		printf("%s", "Введено неверное значение");
		abort();
	}
}


double def_A(double I, double U, double t)
{
	return (I * U * t);
}