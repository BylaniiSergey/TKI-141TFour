# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include <errno.h>


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
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает верно, иначе 1
*/
int main()
{
	int res;
	setlocale(LC_ALL, "RU");
	
	double v1 = get_value("Введите первую скорость (v1): ");

	double v2 = get_value("Введите вторую скорость (v2): ");

	double v3 = get_value("Введите третью скорость (v3): ");

	double t1 = get_value("Введите первое время (t1): ");

	double t2 = get_value("Введите второе время (t2): ");

	double t3 = get_value("Введите третье время (t3): ");

	double t = def_t(v1, v2, v3, t1, t2, t3);
	printf("Время за которое путник одолел первую половину пути: %lf", t);

	return 0;
}

double get_value(const char* message)
{
	double a;
	printf("%s", message);
	int res = scanf_s("%lf", &a);
	if (res != 1 || a < 0)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return a;
}

double def_t(double v1, double v2, double v3, double t1, double t2, double t3)
{
	return (t1+t2+t3)/2;

}