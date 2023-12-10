#include <stdio.h>
#include <locale.h>
#include <errno.h>
#include <math.h>
#include <float.h>
#include <stdlib.h>

/**
* @brief Функция считывающая количество членов последовательности
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return Количество членов последовательности
*/
int get_count();

/**
* @brief Функция считывающая точность вычисления суммы последовательности
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return Точность вычисления суммы последовательности
*/
double get_epsilon();

/**
* @brief Функция расчитывающая сумму членов последовательности
* @param count - количество членов последовательности
* @return Сумма последовательности
*/
double get_count_sum(int count);

/**
* @brief Функция расчитывающая сумму членов последовательности
* @param epsilon - точность вычисления суммы последовательности
* @return Сумма последовательности
*/
double get_epsilon_sum(double epsilon);

/**
* @brief Функция расчитывающая рекурентный член последовательности
* @param k - номер члена последовательности
* @return Значение рекурентного члена последовательности
*/
double get_recurrent(int k);

/**
*@brief Точка входа в программу
*@return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "RU");

	puts("Введите количество членов последовательности:");
	int count = get_count();
	double count_sum = get_count_sum(count);
	printf_s("Суммы %d членов последовательности: %.20lf \n", count, count_sum);

	puts("Введите точность вычисления суммы последовательности:");
	double epsilon = get_epsilon();
	double epsilon_sum = get_epsilon_sum(epsilon);
	printf_s("Суммы членов последовательности с заданной точностью равна: %.20lf", epsilon_sum);

	return EXIT_SUCCESS;
}

int get_count()
{
	int count;
	int result = scanf_s("%d", &count);

	if (result != 1 || count == 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}

	return count;
}

double get_epsilon()
{
	double epsilon;
	int result = scanf_s("%lf", &epsilon);

	if (result != 1 || epsilon >= -DBL_MIN)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}

	return epsilon;
}

double get_count_sum(int count)
{
	double current = 1.0;
	double sum = current;
	for (int k = 1; k < count; k++)
	{
		current *= get_recurrent(k);
		sum += current;
	}
	return sum;
}

double get_epsilon_sum(double epsilon)
{
	double current = 1.0;
	double sum = 0;
	int k = 1;

	while (current < epsilon)
	{
		current *= get_recurrent(k);
		current += sum;
		k++;
	}

	return sum;
}

double get_recurrent(int k)
{
	return - (pow(k + 1, 3) / pow(k, 4));
}