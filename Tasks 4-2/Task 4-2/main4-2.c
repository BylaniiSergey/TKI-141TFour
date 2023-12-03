#include <memory.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/**
* @brief ������� ������� ������� ������: ���������� ��� ������
*/
void names_of_random_and_keyboard();

/**
* @brief ���������������� ����
*/
enum random_or_keybord
{
	Keyboard = 1,
	Random = 2
};

/**
* @brief ������� ����������� � ����������� �������� ������� �� ����
* @param message - ����� ��������� ��� ������������
* @return �������� �������
*/
size_t get_size(char const* message);

/**
* @brief ������� ���������� ������ ��� ������
* @param size - ������ �������
* @return ������
*/
int* init_array(const size_t size);

/**
* @brief ������� ��������� ������ ���������� ������� ��� ������� � ���������� � ����������� �� ������ ������������
* @param size - ������ �������
* @param array - ������
*/
void fill_array(const size_t size, int* array);

/**
* @brief ������� ����������� ���� � ����������
* @param size - ������ �������
* @param array - ������
*/
void fill_keyboard(const size_t size, int* array);

/**
* @brief ������� ����������� ������ ���������� �������
* @param size - ������ �������
* @param array - ������
* @return 1 ���� ��� ������
*/
int fill_random(const size_t size, int* array);

/**
* @brief ������� ��������� ����������� ������
* @param size - ������ �������
* @param array - ������
*/
int print_array(const size_t size, const int* array);

/**
* @brief ������� ����������� � ����������� �������� �� ����
* @param message - ����� ��������� ��� ������������
* @return ��������
*/
int get_value(const char* message);

/**
* @brief ������� ���������� ������ ������������� ������� ����
* @param array - ������������� ������
* @param size - ������
* @return ���������� �������� ������
*/
int* replace_first_negative(const int* const array, size_t size);

/**
* @brief ������� �������������� k ����� ���� ��������� ������� ������ ������
* @param array - ������������� ������
* @param size - ������
* @param k - ������
* @return ���������� �������� ������
*/
int* insert_k(const int* const array, size_t size, int k);

/**
* @brief ������� ���� ������ ���������� �������� �������� ������ ������
* @param array - ������������� ������
* @param size - ������
* @return ���������� ������
*/
size_t find_index_last_divisible(const int* const array, size_t size);

/**
* @brief ������� ��������� ������ �� ��������� �� ������� 3 �������
* @param array - ������������� ������
* @param size - ������
* @return ���������� ����� ������ A
*/
int* get_array_A(const int* const array, size_t size);

/**
* @brief ����� ����� � ���������
* @return ���������� 0, ���� ��������� �������� �����, ����� 1
*/
int main()
{
	setlocale(LC_ALL, "RU");

	size_t size = get_size("������� ������ �������: ");

	int* array = init_array(size);
	fill_array(size, array);

	puts("�������� ������:\n");
	print_array(size, array);
	int* array_with_replaced_first_negative = replace_first_negative(array, size);

	puts("������ � ��������� ������ ������������� ��������� �� 0:\n");
	print_array(size, array_with_replaced_first_negative);

	int k = get_value("������� k: ");
	int* array_with_inserted_k = insert_k(array, size, k);

	puts("������ �� ����������� ������ ����� ���������, ������� ������ ������ (������� � 1):\n");
	print_array(size + 1, array_with_inserted_k);
	int* A_array = get_array_A(array, size);

	puts("������ A, �������������� �� ��������� ������� D �� 3-�� �������:\n");
	print_array(size, A_array);

	return 0;
}

void names_of_random_and_keyboard()
{
	printf_s("���������� � ���������� - %d\n", (int)Keyboard);
	printf_s("��������� ���������� - %d\n", (int)Random);
}

size_t get_size(char const* message)
{
	int size = get_value(message);
	if (size < 0) {
		perror("�������� ������!\n");
		abort();
	}
	return (size_t)size;
}

int* init_array(const size_t size)
{
	int* arr = malloc(size * sizeof(int));
	if (arr == NULL)
	{
		perror("���������� �������� ������ ��� ������!\n");
	}
	return arr;
}

void fill_array(const size_t size, int* array)
{
	puts("��� �� ������ ��������� ������:\n");
	names_of_random_and_keyboard();

	enum random_or_keybord choice = get_value("�������� ������ �������: ");
	switch (choice)
	{
	case Keyboard:
		fill_keyboard(size, array);
		break;
	case Random:
		fill_random(size, array);
		break;
	default:
		perror("�������� �����!!\n");
	}
}

void fill_keyboard(const size_t size, int* array)
{
	const int minimum_limit = get_value("������� ������ ������� �������: ");
	const int maximum_limit = get_value("������� ������� ������� �������: ");
	if (minimum_limit >= maximum_limit)
	{
		errno = EIO;
		perror("�������� �������!\n");
		abort();
	}
	puts("������� ������: ");
	for (size_t i = 0; i < size; i++)
	{
		int c = get_value("");
		if (c < minimum_limit || c > maximum_limit)
		{
			errno = EIO;
			perror("������ �����!\n");
			abort();
		}
		array[i] = c;
	}
}

int fill_random(const size_t size, int* array)
{
	const int minimum_limit = get_value("������� ������ ������� �������: ");
	const int maximum_limit = get_value("������� ������� ������� �������: ");
	unsigned int ttime = time(NULL);
	srand(ttime);
	for (size_t i = 0; i < size; i++)
	{
		array[i] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
	}
	return 1;
}

int print_array(const size_t size, const int* array)
{
	for (size_t i = 0; i < size; i++)
	{
		printf_s("%Iu\t%d\n", i, array[i]);
	}
	return 1;
}

int get_value(const char* message)
{
	int a;
	printf_s("%s", message);
	int res = scanf_s("%d", &a);
	if (res != 1)
	{
		errno = EIO;
		perror("�������� ��������\n");
		abort();
	}
	return a;
}

int* replace_first_negative(const int* const array, size_t size)
{
	int* new_array = init_array(size);
	bool is_first = true;
	for (size_t i=0; i < size; ++i)
	{
		new_array[i] = array[i];
		if (is_first && array[i] < 0)
		{
			new_array[i] = 0;
			is_first = false;
		}
	}
	return new_array;
}

size_t find_index_last_divisible(const int* const array, size_t size)
{
	size_t index = 0;
	bool is_divisible_elements = false;
	for (size_t i = 0; i < size; ++i)
	{
		if (array[i] % (int)(i + 1) == 0)
		{
			is_divisible_elements = true;
			index = i;
		}
	}
	if (!is_divisible_elements)
	{
		perror("��� ���������, ������� ����� �������!\n");
		abort();
	}
	return index;
}

int* insert_k(const int* const array, size_t size, int k)
{
	int* new_array = init_array(size + 1);
	size_t last_divisible_index = find_index_last_divisible(array, size);
	if (last_divisible_index >= size)
	{
		perror("������ ���������� �������� �������� ������� ������ ������� �������!\n");
		abort();
	}
	memcpy(new_array, array, (last_divisible_index + 1) * sizeof(int));
	new_array[last_divisible_index + 1] = k;
	memcpy((new_array + (last_divisible_index + 2)), (array + last_divisible_index + 1), (size - last_divisible_index - 1) * sizeof(int));
	return new_array;
}

int* get_array_A(const int* const array, size_t size)
{
	int* new_array = init_array(size);
	for (size_t i = 0; i < size; ++i)
	{
		if ((i + 1) % 2 == 0)
		{
			new_array[i] = (i - 1) * array[i];
		}
		else
		{
			new_array[i] = array[i] * i * 2;
		}
	}
	return new_array;
}
