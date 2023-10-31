#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <errno.h>
#include <float.h>
#include <math.h>

/**
* @brief Пользовательский ввод
*/
enum user_input
{
	/**
	* @brief Периметр
	*/
	PERIMETER = 1,
	/**
	* @brief Площадь
	*/
	SQUARE = 2,
	/**
	* @brief Длина диагонали
	*/
	DIAGONAL = 3
};

/**
* @brief Получает целое значение
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return Целое значение
*/
int get_choice();

/**
* @brief Функция для проверки ввода стороны фигуры
* @remarks Экстренное завершение программы, в случае неправильного ввода
* @return Сторона фигуры
*/
double get_side();

/**
* @brief Функция для подсчёта периметра прямоугольника
* @param a - первая сторона прямоугольника
* @param b - вторая сторона прямоугольника
* @return Периметр прямоугольника
*/
double get_perimeter(double a, double b);

/**
* @brief Функция для подсчёта площади прямоугольника
* @param a - первая сторона прямоугольника
* @param b - вторая сторона прямоугольника
* @return Площадь прямоугольника
*/
double get_square(double a, double b);

/**
* @brief Функция для подсчёта периметра прямоугольника
* @param a - первая сторона прямоугольника
* @param b - вторая сторона прямоугольника
* @return Периметр прямоугольника
*/
double get_diagonal(double a, double b);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "RU");

	puts("Введите номер соответствующий заданию:\n");
	printf_s("%d - для вычисления пириметра прямоугольника\n", PERIMETER);
	printf_s("%d - для вычисления площади прямоугольника\n", SQUARE);
	printf_s("%d - для вычисления длины диагонали прямоугольника\n", DIAGONAL);

	int choice = get_choice();

	enum UserInput figure = (enum user_input)choice;

	puts("Введите первую сторону прямоугольника: ");
	double a = get_side();

	puts("Введите вторую сторону прямоугольника: ");
	double b = get_side();

	switch (figure)
	{
	case PERIMETER:
	{
		double perimeter = get_perimeter(a,b);
		printf_s("%lf - периметр прямоугольника", perimeter);
		break;
	}
	case SQUARE:
	{
		double squar = get_square(a,b);
		printf_s("%lf - площадь прямоугольника",squar);
		break;
	}
	case DIAGONAL:
	{
		double diagonal = get_diagonal(a,b);
		printf_s("%lf - длина диагонали треугольника", diagonal);
		break;
	}
	default:
	{
		errno = EDOM;
		perror("Ошибка ввода");
		return EXIT_FAILURE;
	}
	}

	return EXIT_SUCCESS;
}

int get_choice()
{
	int choice;
	int result = scanf_s("%d", &choice);
	if (result != 1)
	{
		errno = EIO;
		perror("Ошибка ввода");
		abort();
	}

	return choice;
}

double get_side()
{
	double side;
	int result = scanf_s("%lf", &side);
	if (result != 1 || side <= 0)
	{
		errno = EIO;
		perror("Введено неправильное значение");
		abort();
	}
	return side;
}

double get_perimeter(double a, double b)
{
	return (a + b) * 2;
}

double get_square(double a, double b)
{
	return a * b;
}

double get_diagonal(double a, double b)
{
	return sqrt((a * a) + (b * b));
}