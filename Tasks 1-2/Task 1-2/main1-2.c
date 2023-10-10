#include <stdio.h>
#include <math.h>


/**
* @brief Перевод грамм в унции
* @return Возвращает унции
*/
double gram_to_ounces(double gram);


/**
* @brief Получает вещественное число
* @return Возвращает вещественное число
*/
double getscanf_s(double gram);


/**
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе не 0
*/
int main()
{
	double gram;
	int res = scanf_s("%lf", &gram);
	getscanf_s(res);
	double ounces = gram_to_ounces(gram);
	printf("%lf", ounces);
	return 0;
}


double getscanf_s(double gram)
{
	if (gram != 1)
	{
		printf("%lf", "Введено неверное значение");
		abort();
	}
}


double gram_to_ounces(double gram)
{
	return gram * 28.3;
}
