# include <stdio.h>
# include <locale.h>
# include <stdlib.h>
# include <errno.h>
# include <stdbool.h>
# include <float.h>

/**
* @brief ������� ����������� � ����������� �������� �� ����
* @param message - ����� ��������� ��� ������������
* @return ��������
*/
double get_value(const char* message);

/**
* @brief ������� ��� ���������� ������� �� ������� ������ ������ ������ �������� ����
* @param v1 - ������ ��������
* @param v2 - ������ ��������
* @param v3 - ������ ��������
* @param t1 - ������ �����
* @param t2 - ������ �����
* @param t3 - ����� �����
* @return ����� �� ������� ������ ��������� ������ �������� ����
*/
double def_t(double v1, double v2, double v3, double t1, double t2, double t3);

/**
* @brief ������� ��� ���������� ���������
* @param v -  ��������
* @param t -  �����
* @return ��������� ������� ������ ������ 
*/
double get_way(double v, double t);

/**
* @brief ������� ��� ���������� �������
* @param s -  ���������
* @param v -  ��������
* @return ����� ������� ������ ������
*/
double get_time(double s, double v);

/**
* @brief ������� ��� �������� ���������
* @param s -  ���������
* @param half_way -  ��� ����
* @return ��������
*/
bool belong_to_interval(double s, double half_way);

/**
* @brief ����� ����� � ���������
* @return ���������� 0, ���� ��������� �������� �����, ����� 1
*/
int main()
{
	setlocale(LC_ALL, "RU");

	double v1 = get_value("������� ������ �������� (v1): ");

	double v2 = get_value("������� ������ �������� (v2): ");

	double v3 = get_value("������� ������ �������� (v3): ");

	double t1 = get_value("������� ������ ����� (t1): ");

	double t2 = get_value("������� ������ ����� (t2): ");

	double t3 = get_value("������� ������ ����� (t3): ");

	printf("����� �� ������� ������ ��������� ������ �������� ����: %lf", def_t(v1, v2, v3, t1, t2, t3));

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