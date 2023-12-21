#include <memory.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/**
* @brief Функция выводит вариант выбора: Клавиатура или Рандом
*/
void names_of_random_and_keyboard();

/**
* @brief Пользовательский ввод
*/
enum random_or_keybord
{
	Keyboard = 1,
	Random = 2
};

/**
* @brief Функция принимающая и проверяющая значение размера на ввод
* @param message - текст сообщения для пользователя
* @return Значение размера
*/
size_t get_size(char const* message);

/**
* @brief Функция выделяющая память под массив
* @param size - размер массива
* @return Массив
*/
int* init_array(const size_t size);

/**
* @brief Функция запалняет массив случайными числами или числами с клавиатуры в зависимости от выбора пользователя
* @param size - размер массива
* @param array - массив
*/
void fill_array(const size_t size, int* array);

/**
* @brief Функция считывающая ввод с клавиатуры
* @param size - размер массива
* @param array - массив
*/
void fill_keyboard(const size_t size, int* array);

/**
* @brief Функция заполняющая массив рандомными числами
* @param size - размер массива
* @param array - массив
* @return 1 если все хорошо
*/
int fill_random(const size_t size, int* array);

/**
* @brief Функция выводящая заполненный массив
* @param size - размер массива
* @param array - массив
*/
int print_array(const size_t size, const int* array);

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
int get_value(const char* message);

/**
* @brief Функция заменяющая первый отрицательный элемент нулём
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает изменёный массив
*/
int* replace_first_negative(const int* const array, size_t size);

/**
* @brief Функция вставляющающая k после всех элементов кратную своему номеру
* @param array - целочисленный массив
* @param size - размер
* @param k - элемен
* @return Возвращает изменёный массив
*/
int* insert_k(const int* const array, size_t size, int k);

/**
* @brief Функция ищет индекс последнего элемента кратного своему номеру
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает индекс
*/
size_t find_index_last_divisible(const int* const array, size_t size);

/**
* @brief Функция формирует массив из исходного по условию 3 задания
* @param array - целочисленный массив
* @param size - размер
* @return Возвращает новый массив A
*/
int* get_array_A(const int* const array, size_t size);

/**
* @brief Функция удаляющая массив
* @param array - массив
*/
void delete_array(int* array);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
	setlocale(LC_ALL, "RU");

	size_t size = get_size("Введите размер массива: ");

	int* array = init_array(size);
	fill_array(size, array);

	puts("Исходный массив:\n");
	print_array(size, array);
	int* array_with_replaced_first_negative = replace_first_negative(array, size);

	puts("Массив с заменённым первым отрицательным элементом на 0:\n");
	print_array(size, array_with_replaced_first_negative);

	int k = get_value("Введите k: ");
	int* array_with_inserted_k = insert_k(array, size, k);

	puts("Массив со вставленным числом после элементов, кратных своему номеру (начиная с 1):\n");
	print_array(size + 1, array_with_inserted_k);
	int* A_array = get_array_A(array, size);

	puts("Массив A, сформированный из исходного массива D по 3-му условию:\n");
	print_array(size, A_array);
	delete_array(array);

	return 0;
}

void names_of_random_and_keyboard()
{
	printf_s("Заполнение с клавиатуры - %d\n", (int)Keyboard);
	printf_s("Случайное заполнение - %d\n", (int)Random);
}

size_t get_size(char const* message)
{
	int size = get_value(message);
	if (size < 0) {
		perror("Неверный массив!\n");
		abort();
	}
	return (size_t)size;
}

int* init_array(const size_t size)
{
	int* arr = malloc(size * sizeof(int));
	if (arr == NULL)
	{
		perror("Невозможно выделить мапять под массив!\n");
	}
	return arr;
}

void fill_array(const size_t size, int* array)
{
	puts("Как Вы хотите заполнить массив:\n");
	names_of_random_and_keyboard();

	enum random_or_keybord choice = get_value("Выберите нужный вариант: ");
	switch (choice)
	{
	case Keyboard:
		fill_keyboard(size, array);
		break;
	case Random:
		fill_random(size, array);
		break;
	default:
		perror("Неверный выбор!!\n");
	}
}

void fill_keyboard(const size_t size, int* array)
{
	const int minimum_limit = get_value("Введите нижнюю границу массива: ");
	const int maximum_limit = get_value("Введите верхнюю границу массива: ");
	if (minimum_limit >= maximum_limit)
	{
		errno = EIO;
		perror("Неверные границы!\n");
		abort();
	}
	puts("Введите массив: ");
	for (size_t i = 0; i < size; i++)
	{
		int c = get_value("");
		if (c < minimum_limit || c > maximum_limit)
		{
			errno = EIO;
			perror("Ошибка ввода!\n");
			abort();
		}
		array[i] = c;
	}
}

int fill_random(const size_t size, int* array)
{
	const int minimum_limit = get_value("Введите нижнюю границу массива: ");
	const int maximum_limit = get_value("Введите верхнюю границу массива: ");
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
		perror("Неверное значение\n");
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
		perror("Нет элементов, кратных своим номерам!\n");
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
		perror("Индекс последнего кратного элемента массива больше размера массива!\n");
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

void delete_array(int* array)
{
	if (array != NULL)
	{
		free(array);
	}
}
