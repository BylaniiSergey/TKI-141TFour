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
* @brief Функция находящая индекс элементов, значения которых кратны 3
* @param size - размер массива
* @param array - массив
*/
void print_indexes_3(const int* const arr, size_t size);

/**
* @brief Функция находящая последние k элементов массива и заменяющего  их на противоположные
* @param size - размер массива
* @param array - массив
* @param k - кол-во элементов с конца которых надо заменить
* @return Последние k элементов изменёного массива
*/
int* replace_last_k(const int* const arr, size_t size, size_t k);

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
void print_array(const size_t size, const int* array);

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
int get_value(const char* message);

/**
* @brief Функция проверяющая массив есть ли пара соседних элементов с суммой, равной заданному числу
* @param size - размер массива
* @param array - массив
* @param checkSum - сумма которой равны два соседних элемента
*/
bool is_coulple_sum(const size_t size, const int* array, int checkSum);

/**
* @brief Функция печатает есть ли пары массива 
* @param size - размер массива
* @param array - массив
* @param checkSum - сумма которой равны два соседних элемента
*/
void print_couples(const size_t size, const int* array, int checkSum);

/**
* @brief Функция выводит вариант выбора: Клавиатура или Рандом
*/
void names_of_random_and_keyboard();

enum random_or_keybord
{
    Keyboard = 1,
    Random = 2
};

/**
* @brief Функция запалняет массив случайными числами или числами с клавиатуры в зависимости от выбора пользователя
* @param size - размер массива
* @param array - массив
*/
void fill_array(const size_t size, int* array);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main()
{
    setlocale(LC_ALL, "RU");

    size_t size = get_size("Введите размер массива: ");
    int* arr = init_array(size);
    fill_array(size, arr);

    puts("Исходный массив: \n");
    print_array(size, arr);
    print_array(size, replace_last_k(arr, size, k));
    print_indexes_3(arr, size);

    print_couples(size, arr, checkSum);

    return 0;
}

void names_of_random_and_keyboard()
{
    printf_s("Keyboard - %d\n", (int)Keyboard);
    printf_s("Random - %d\n", (int)Random);
}

int* replace_last_k(const int* const arr, size_t size, size_t k)
{
    size_t k = get_size("Введите k: ");
    int* arr_1 = replace_last_k(arr, size, k);
    int* arr_k = init_array(size);
    memcpy(arr_k, arr, size * sizeof(int));
    for (size_t i = size - k; i < size; ++i)
    {
        arr_k[i] = -arr_k[i];
    }
    return arr_k;
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

int* init_array(const size_t size)
{
    int* arr = malloc(size * sizeof(int));
    if (arr == NULL)
    {
        perror("Неудалось выделить память под массив!\n");
        abort();
    }
    return arr;
}

void fill_array(const size_t size, int* array)
{
    puts("Как Вы хотите заполнить массив:\n");
    names_of_random_and_keyboard();
    enum random_or_keybord choice = get_value("Выберите нужный вариант: ");
    switch (choice) {
    case Keyboard:
        fill_keyboard(size, array);
        break;
    case Random:
        fill_random(size, array);
        break;
    default:
        perror("Неверный выбор!\n");
        abort();
    }
}

void fill_keyboard(const size_t size, int* array)
{
    const int minimum_limit = get_value("Введите нижнюю границу массива: ");
    const int maximum_limit = get_value("Введите верхнюю границу массива: ");
    if (minimum_limit >= maximum_limit)
    {
        errno = EIO;
        perror("Неверные границы масив");
        abort();
    }
    puts("Введите массива: ");
    for (size_t i = 0; i < size; i++)
    {
        int c = get_value("");
        if (c < minimum_limit || c > maximum_limit)
        {
            errno = EIO;
            perror("Неверное значение");
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

void print_array(const size_t size, const int* array)
{
    for (size_t i = 0; i < size; i++)
    {
        printf_s("%Iu\t%d\n", i, array[i]);
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
        perror("Ошибка ввода");
        abort();
    }
    return a;
}

void print_indexes_3(const int* const arr, size_t size)
{
    puts("Индексы элементов, кратных 3:\n");
    for (size_t i = 0; i < size; ++i)
    {
        if (arr[i] % 3 == 0)
        {
            printf_s("%d ", i);
        }
    }
    puts("\n");
}

bool is_coulple_sum(const size_t size, const int* array, int checkSum)
{
    for (size_t i = 0; i < size - 1; i++)
    {
        int current = array[i];
        int next = array[i + 1];
        if (current + next == checkSum)
        {
            return true;
        }
    }
    return false;
}

void print_couples(const size_t size, const int* array, int checkSum)
{
    if (is_couple_sum(size, array, checkSum)) 
    {
        puts("Присутствуют\n")
    }
    else 
    {
        puts("Отсутствуют\n");
    }
}