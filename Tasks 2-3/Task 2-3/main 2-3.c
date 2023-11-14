# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <float.h>

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
double get_value(const char* message);

/**
* @brief Функция для нахождения времени за которое путник одолел первую половину пути
* @param v1 - первая скорость
* @param v2 - вторая скорость
* @param v3 - третья скорость
* @param t1 - первое время
* @param t2 - второе время
* @param t3 - треть время
* @return Время за которое путник преодолел первую половину пути
*/
double def_t(double v1, double v2, double v3, double t1, double t2, double t3);

/**
* @brief Функция для нахождения растояния
* @param v -  скорость
* @param t -  время
* @return Растояние которое прошёл путник
*/
double get_way(double v, double t);

/**
* @brief Функция для нахождения времени
* @param s -  растояние
* @param v -  скорость
* @return Время которое прошёл путник
*/
double get_time(double s, double v);

/**
* @brief Функция для приверки интервала
* @param s -  растояние
* @param half_way -  пол пути
* @return Интервал
*/
bool belong_to_interval(double s, double half_way);

/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает верно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "RU");

	double v1 = get_value("Введите первую скорость (v1): ");

	double v2 = get_value("Введите вторую скорость (v2): ");

	double v3 = get_value("Введите третью скорость (v3): ");

	double t1 = get_value("Введите первое время (t1): ");

	double t2 = get_value("Введите второе время (t2): ");

	double t3 = get_value("Введите третье время (t3): ");

	printf("Время за которое путник преодолел первую половину пути: %lf", def_t(v1, v2, v3, t1, t2, t3));

	return 0;
}

double get_value(const char* message)
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

double get_way(double v, double t)
{
	return v * t;
}

double def_t(double v1, double v2, double v3, double t1, double t2, double t3)
{
	const double s1 = get_way(v1, t1);
	const double s2 = get_way(v2, t2);
	const double s3 = get_way(v3, t3);
	double half_way = (s1 + s2 + s3) / 2;
	if (belong_to_interval(s1, half_way))
	{
		return get_time(half_way, v1);
	}
	if (belong_to_interval(s1 + s2, half_way))
	{
		return t1 + get_time(half_way - s1, v2);
	}

	if (belong_to_interval(s1 + s2 + s3, half_way))
	{
		return t1 + t2 + get_time(half_way - s1 - s2, v3);
	}
}

double get_time(double s, double v)
{
	return s / v;
}

bool belong_to_interval(double s, double half_way)
{
	return s - half_way > -DBL_EPSILON;
}