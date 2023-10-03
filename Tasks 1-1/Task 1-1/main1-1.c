#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*
* @brief ���������� ��������� ������� a
* @param �������� "x" ��� ������� a
* @param �������� "y" ��� ������� a
* @param �������� "z" ��� ������� a
**/
double aFunc(double x, double y, double z);


/*
* @brief ���������� ��������� ������� a
* @param �������� "x" ��� ������� a
* @param �������� "y" ��� ������� a
* @param �������� "z" ��� ������� a
**/
double bFunc(double x, double y, double z);


/*
* @brief ����� ����� � ���������
* @return ���������� 0, ���� ��������� �������� ���������, ����� �� 0
**/
int main()
{
    const double x = -2.9;
    const double y = -15.5;
    const double z = 1.5;
    double a = aFunc(x, y, z);
    double b = bFunc(x, y, z);
    printf("a=%f\n", a);
    printf("b=%f\n", b);
    return 0;
}


double aFunc(double x, double y, double z)
{
    return (sqrt((pow(x, 2)) + y)) - (pow(y, 2)) * (pow(sin((x + z) / x), 3));
}


double bFunc(double x, double y, double z)
{
    double denominator = sqrt((pow(z, 2)) + (pow(y, 2)));
    return (pow(cos(pow(x, 3)), 2)) - (x / denominator);
}