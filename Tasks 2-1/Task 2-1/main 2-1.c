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
* @brief Функция для ввода сторон прямоугольника
* @return Функцию для вычесления периметра прямоугольника по заданным сторонам
*/
double get_perimeter();

/**
* @brief Функция для подсчёта периметра прямоугольника
* @param a - первая сторона прямоугольника
* @param b - вторая сторона прямоугольника
* @return Периметр прямоугольника
*/
double get_perimeter_area(double a, double b);

/**
* @brief Функция для ввода сторон прямоугольника
* @return Функцию для вычесления площади прямоугольника по заданным сторонам
*/
double get_square();

/**
* @brief Функция для подсчёта площади прямоугольника
* @param a - первая сторона прямоугольника
* @param b - вторая сторона прямоугольника
* @return Площадь прямоугольника
*/
double get_square_area(double a, double b);

/**
* @brief Функция для ввода сторон прямоугольника
* @return Функцию для вычесления периметра прямоугольника по заданным сторонам
*/
double get_diagonal();

/**
* @brief Функция для подсчёта периметра прямоугольника
* @param a - первая сторона прямоугольника
* @param b - вторая сторона прямоугольника
* @return Периметр прямоугольника
*/
double get_diagonal_area(double a, double b);

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

	double area;
	int choice = get_choice();

	enum UserInput figure = (enum user_input)choice;

	switch (figure)
	{
	case PERIMETER:
	{
		area = get_perimeter();
		printf_s("%lf - пириметр прямоугольника", area);
		break;
	}
	case SQUARE:
	{
		area = get_square();
		printf_s("%lf - площадь прямоугольника", area);
		break;
	}
	case DIAGONAL:
	{
		area = get_diagonal();
		printf_s("%lf - длина диагонали треугольника", area);
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

double get_perimeter()
{
	puts("Введите первую сторону прямоугольника: ");
	double a = get_side();
	puts("Введите вторую сторону прямоугольника: ");
	double b = get_side();

	return get_perimeter_area(a, b);
}

double get_perimeter_area(double a, double b)
{
	return (a + b)*2;
}

double get_square()
{
	puts("Введите первую сторону прямоугольника: ");
	double a = get_side();
	puts("Введите вторую сторону прямоугольника: ");
	double b = get_side();

	return get_square_area(a, b);
}

double get_square_area(double a, double b)
{
	return a * b;
}

double get_diagonal()
{
	puts("Введите первую сторону прямоугольника: ");
	double a = get_side();
	puts("Введите вторую сторону прямоугольника: ");
	double b = get_side();

	return get_diagonal_area(a, b);
}

double get_diagonal_area(double a, double b)
{
	return sqrt((a*a)+(b*b));
}