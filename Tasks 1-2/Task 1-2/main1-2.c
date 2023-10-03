#include <stdio.h>
#include <math.h>


/*
* @brief Перевод грамм в унции
* @return Возвращает унции
* */
double gram_to_ounces( );


/*
* @brief Точка входа в программу
* @return Возвращает 0, если программа работает корректно, иначе не 0
* */
int main()
{
	double gram;
	scanf_s("%lf", &gram);
	double ounces = gram_to_ounces(gram);
	printf("%lf\n", ounces);
	return 0;
}


double gram_to_ounces(double gram)
{
	double ounces = gram * 28.3;
	return ounces;
}