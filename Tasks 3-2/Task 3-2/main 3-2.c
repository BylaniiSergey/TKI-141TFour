#include<stdio.h>
#include<math.h>
#include <stdlib.h>	
#include <errno.h>

/**	
 * @brief Формула для расчета факториала	
 * @param x - число от которого факториал должен быть посчитан
 * @return факториал
 */
double factorial(double x);	

/**	
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
double get_value(const char* message);

/**
*@brief Точка входа в программу
*@return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
    double n, answ;	
    answ = 0;
    n = get_value("Enter n: ");	 
    for (int k = 1; k <= n; k++)
    {
        answ = answ + (pow(k, 4) / (factorial(k)));	        
    }
    printf("%lf\n", answ);
}

double factorial(double x)	
{
    if (x < 2)	
    {
        return 1;	       
    }
    else	    
    {
        return ((pow(x, 3)+(3*pow(x,2))+(3*x)+1)/pow(x,4));
    }
}

double get_value(const char* message)
{
    double a;	 
    printf("%s", message);	    
    int res = scanf_s("%lf", &a);	    
    if (res != 1)	   
    {
        errno = EIO;	        
        perror("Wrong value");	        
        abort();	       
    }
    return a;	
}