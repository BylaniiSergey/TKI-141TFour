#include <memory.h>
#include <stdlib.h>
#include <float.h>
#include <errno.h>
#include <time.h>
#include <stdio.h>
#include <stdbool.h>
#include <locale.h>

/**
* @brief Пользовательский ввод
*/
enum random_or_keybord
{
    Keyboard = 1,
    Random = 2
};

/**
* @brief Функция выводит вариант выбора: Клавиатура или Рандом
*/
void names_of_random_and_keyboard();

/**
* @brief Функция принимающая и проверяющая значение размера на ввод
* @param message - текст сообщения для пользователя
* @return Значение размера
*/
size_t get_size(char const* message);

/**
* @brief Функция выделяющая память под двумерный массив
* @param n - количество строк
* @param m - количество столбцов
* @return Массив
*/
int** init_array(const size_t n, const size_t m);

/**
* @brief Функция заполняет массив случайными числами или числами с клавиатуры в зависимости от выбора пользователя
* @param n - количество строк
* @param m - количество столбцов
* @param array - массив
*/
void fill_array(int** array, size_t n, size_t m);

/**
* @brief Функция считывающая ввод с клавиатуры
* @param n - количество строк
* @param m - количество столбцов
* @param array - массив
*/
void fill_keyboard(int** array, size_t n, size_t m);

/**
* @brief Функция заполняющая массив рандомными числами
* @param n - количество строк
* @param m - количество столбцов
* @return 1 если все хорошо
*/
void fill_random(int** array, const size_t n, const size_t m);

/**
* @brief Функция выводящая заполненный массив
* @param n - количество строк
* @param m - количество столбцов
* @param array - массив
*/
void print_array(const int* const* array, size_t n, size_t m);

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
int get_value(const char* message);

/**
* @brief Функция удаляющая массив
* @param array - массив
* @param n - количество строк
*/
void delete_array(int** arr, size_t n);

/**
* @brief Функция которая ищет максимальное значение в строке массива
* @param array_string - строка массива
* @param m - количество столбцов
* @return Максимальное значение в строке массива
*/
int find_max_in_string(int const* const array_string, size_t m);

/**
* @brief Функция копирующая массив
* @param arr - массив
* @param n - количество строк
* @param m - количество столбцов
* @return Возвращает копию массива
*/
int** copy_array(const int* const* const arr, size_t n, size_t m);

/**
* @brief Заминить максимальный элемент в каждой строке на противоположный по знаку
* @param arr - массив
* @param n - количество строк
* @param m - количество столбцов
* @return Возвращает изменённый массив
*/
int** replace_max_in_each_string(const int* const* const arr, size_t n, size_t m);

/**
* @brief Функция создаёт одномерный массив размером m
* @param m - количество столбцов
* @return Возвращает созданный одномерный массив
*/
int* init_single_array(size_t m);

/**
* @brief Функция ищет максимальный элемент
* @param arr - массив
* @param n - количество строк
* @param m - количество столбцов
* @return Возвращает номер столбца максимального элемента
*/
size_t find_last_max_column_index(const int* const* const arr, size_t n, size_t m);

/**
* @brief Функция вставляет элемент в строку массива
* @param array_string - строка массива
* @param elem - элемент который надо вставить
* @param index - индекс после которго надо вставить элемент
* @param m - количество столбцов
* @return Возвращает изменённую строку массива
*/
int* insert_to_string(const int* const array_string, size_t m, int elem, size_t index);

/**
* @brief Функция вставляющая после всех столбцов, содержащих максимальный элемент столбец из нулей
* @param arr - массив
* @param n - количество строк
* @param m - количество столбцов
* @return Возвращает изменённый массив
*/
int** insert_max(const int* const* const arr, size_t n, size_t m);

/**
* @brief Функция выделяющая память под массив указателей
* @param n - размер массива
* @return Возвращает массив указателей
*/
int** init_array_of_ptrs(size_t n);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main() {
    setlocale(LC_ALL, "RU");

    size_t n = get_size("Введите количество строк в массиве: ");
    size_t m = get_size("Введите количество столбцов в массиве: ");

    int** arr = init_array(n, m);
    fill_array(arr, n, m);

    puts("Исходный массив:\n");
    print_array(arr, n, m);
    int** first_arr = replace_max_in_each_string(arr, n, m);

    puts("Первое задание:\n");
    print_array(first_arr, n, m);
    int** second_arr = insert_max(arr, n, m);

    puts("Второе задание:\n");
    print_array(second_arr, n, m + 1);

    delete_array(arr, n);
    delete_array(first_arr, n);
    delete_array(second_arr, n);

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
    if (size < 0)
    {
        perror("Неверный размер!\n");
        abort();
    }
    return (size_t)size;
}

int** init_array(const size_t n, const size_t m)
{
    int** arr = (int**)malloc(n * sizeof(int*));
    if (arr == NULL)
    {
        perror("Невозможно выделить память под массив!\n");
    }
    for (size_t i = 0; i < n; ++i)
    {
        arr[i] = init_single_array(n);
    }
    return arr;
}

void fill_array(int** array, size_t n, size_t m)
{
    puts("Как Вы хотите заполнить массив:\n");
    names_of_random_and_keyboard();
    enum random_or_keybord choice = get_value("Выберите нужный вариант: ");
    switch (choice)
    {
    case Keyboard:
        fill_keyboard(array, n, m);
        break;
    case Random:
        fill_random(array, n, m);
        break;
    default:
        perror("Неверный выбор!!\n");
    }
}

void fill_keyboard(int** array, size_t n, size_t m)
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
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; ++j)
        {
            int c = get_value("");
            if (c < minimum_limit || c > maximum_limit)
            {
                errno = EIO;
                perror("Ошибка ввода!\n");
                abort();
            }
            array[i][j] = c;
        }
    }
}

void fill_random(int** array, const size_t n, const size_t m)
{
    const int minimum_limit = get_value("Введите нижнюю границу массива: ");
    const int maximum_limit = get_value("Введите верхнюю границу массива: ");
    unsigned int ttime = time(NULL);
    srand(ttime);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; ++j)
        {
            array[i][j] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
        }
    }
}

void print_array(const int* const* array, size_t n, size_t m)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < m; ++j)
        {
            printf_s("%d\t", array[i][j]);
        }
        puts("\n");
    }
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

void delete_array(int** arr, size_t n)
{
    if (arr != NULL) 
    {
        for (size_t i = 0; i < n; ++i)
        {
            if (arr[i] != NULL) {
                free(arr[i]);
            }
        }
        free(arr);
    }
}

int find_max_in_string(int const* const array_string, size_t m)
{
    int max = array_string[0];
    for (size_t i = 1; i < m; ++i)
    {
        if (array_string[i] > max)
        {
            max = array_string[i];
        }
    }
    return max;
}

int** copy_array(const int* const* const arr, size_t n, size_t m)
{
    int** new_arr = init_array(n, m);
    for (size_t i = 0; i < n; ++i)
    {
        memcpy(new_arr[i], arr[i], m * sizeof(int));
    }
    return new_arr;
}

int** replace_max_in_each_string(const int* const* const arr, size_t n, size_t m)
{
    int** tmp = copy_array(arr, n, m);
    for (size_t i = 0; i < n; ++i)
    {
        int max_in_string = find_max_in_string(tmp[i], m);
        for (size_t j = 0; j < m; ++j)
        {
            if (tmp[i][j] == max_in_string)
            {
                tmp[i][j] = -tmp[i][j];
            }
        }
    }
    return tmp;
}

int* init_single_array(size_t m)
{
    int* array_string = malloc(m * sizeof(int));
    if (array_string == NULL)
    {
        perror("Невозможно выделить память под массив!\n");
    }
    return array_string;
}

size_t find_last_max_column_index(const int* const* const arr, size_t n, size_t m)
{
    int max = arr[0][0];
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            if (arr[i][j] >= max)
            {
                max = arr[i][j];
            }
        }
    }
    size_t column_index = 0;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j)
        {
            if (arr[i][j] == max && j > column_index)
            {
                column_index = j;
            }
        }
    }
    return column_index;
}

int** init_array_of_ptrs(size_t n)
{
    int** ptr_array = (int**)malloc(n * sizeof(int*));
    if (ptr_array == NULL)
    {
        perror("Невозможно выделить память под массив!\n");
    }
    return ptr_array;
}

int* insert_to_string(const int* const array_string, size_t m, int elem, size_t index)
{
    int* new_array_string = init_single_array(m + 1);
    memcpy(new_array_string, array_string, (index + 1) * sizeof(int));
    new_array_string[index + 1] = elem;
    memcpy(new_array_string + index + 2, array_string + index + 1, (m - index - 1) * sizeof(int));
    return new_array_string;
}

int** insert_max(const int* const* const arr, size_t n, size_t m)
{
    int** new_arr = init_array_of_ptrs(n);
    size_t index = find_last_max_column_index(arr, n, m);
    for (size_t i = 0; i < n; ++i) 
    {
        new_arr[i] = insert_to_string(arr[i], m, 0, index);
    }
    return new_arr;
}