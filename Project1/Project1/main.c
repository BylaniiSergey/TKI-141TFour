#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <locale.h>

/**
* @brief ������� ����������� � ����������� �������� �� ����
* @param message - ����� ��������� ��� ������������
* @return ��������
*/
double get_step(const char* message);

/**
* @brief ������� ����������� � ����������� �������� �� ����
* @param message - ����� ��������� ��� ������������
* @return ��������
*/
double get_value(const char* message);

/**
 * @brief ������� ������������ �������� ������� � ������ �����
 * @param x - �����
 * @return �������� ������� � ����� x
 */
double function(double x);

/**
* @brief ������� ��� s_i
* @param i -  ���������
* @param x -  �����
* @return s_i
*/
double get_s_i(double i, double x);

/**
 * @brief ������� ������������ �������� ����� ���� � ���� �����.
 * @param x - �����.
 * @return �������� ����� ���� � ����� x.
 */
double summ(double x, double e);

/**
* @brief ����� ����� � ���������
* @return ���������� 0, ���� ��������� �������� �����, ����� 1
*/
int main()
{
	setlocale(LC_ALL, "RU");
	double a = get_value("�������(a) : ");
	double x = a;
	double b = get_value("�������(b) : ");
	double step = get_step("Enter step: ");
	double e = pow(30, -5);
	for (double i = a; i - b <= DBL_EPSILON; i += step)
	{
		printf("%lf\t%lf\t%lf\t\n", i, function(i), summ(i, e));
	}
	return 0;
}

double function(double x)
{
	return (1 / 4) * log((1 + x) / (1 - x)) + (1 / 2) * atan(x);
}

double get_s_i(double i, double x)
{
	return (4 * i * pow(x, 4) + pow(x, 4)) / (4 * i + 5);
}

double summ(double x, double i)
{
	double sum = 0;
	int i = 1;
	double get_s_i( i, x);
	sum +=  get_s_i(i, x);
	for (int i = 2; get_s_i(i, x) - sum <= DBL_EPSILON; i++)
	{
		double get_s_i(i, x) += (4 * i * pow(x, 4) + pow(x, 4)) / (4 * i + 5);
		sum += get_s_i(i, x);
	}
	return sum;
}

double get_step(const char* message)
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

double get_value(const char* message)
{
	double b;
	printf("%s", message);
	int res = scanf_s("%lf", &b);
	if (res != 1 || b <= 0)
	{
		errno = EIO;
		perror("Wrong value");
		abort();
	}
	return b;
}
