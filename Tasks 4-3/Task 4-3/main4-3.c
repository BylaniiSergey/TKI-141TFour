#include <memory.h>
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
* @param row - количество строк
* @param columns - количество столбцов
* @return Массив
*/
int** init_array(const size_t row, const size_t columns);

/**
* @brief Функция заполняет массив случайными числами или числами с клавиатуры в зависимости от выбора пользователя
* @param row - количество строк
* @param columns - количество столбцов
* @param array - массив
*/
void fill_array(int** array, size_t row, size_t columns);

/**
* @brief Функция считывающая ввод с клавиатуры
* @param row - количество строк
* @param columns - количество столбцов
* @param array - массив
*/
void fill_keyboard(int** array, size_t row, size_t columns);

/**
* @brief Функция заполняющая массив рандомными числами
* @param row - количество строк
* @param columns - количество столбцов
*/
void fill_random(int** array, const size_t row, const size_t columns);

/**
* @brief Функция выводящая заполненный массив
* @param row - количество строк
* @param columns - количество столбцов
* @param array - массив
*/
void print_array(const int* const* array, size_t row, size_t columns);

/**
* @brief Функция принимающая и проверяющая значение на ввод
* @param message - текст сообщения для пользователя
* @return Значение
*/
int get_value(const char* message);

/**
* @brief Функция удаляющая массив
* @param array - массив
* @param row - количество строк
*/
void delete_array(int*** arr, size_t row);

/**
* @brief Функция которая ищет максимальное значение в строке массива
* @param row - строка массива
* @param columns - количество столбцов
* @return Максимальное значение в строке массива
*/
int find_max_in_row(int const* const row, size_t columns);

/**
* @brief Функция копирующая массив
* @param arr - массив
* @param row - количество строк
* @param columns - количество столбцов
* @return Возвращает копию массива
*/
int** copy_array(const int* const* const arr, size_t row, size_t columns);

/**
* @brief Заминить максимальный элемент в каждой строке на противоположный по знаку
* @param arr - массив
* @param row - количество строк
* @param columns - количество столбцов
* @return Возвращает изменённый массив
*/
int** replace_max_in_each_row(const int* const* const arr, size_t row, size_t columns);

/**
* @brief Функция создаёт одномерный массив размером m
* @param columns - количество столбцов
* @return Возвращает созданный одномерный массив
*/
int* init_single_array(size_t columns);

/**
* @brief Функция ищет максимальный элемент
* @param arr - массив
* @param row - количество строк
* @param columns - количество столбцов
* @return Возвращает номер столбца максимального элемента
*/
size_t find_last_max_column_index(const int* const* const arr, size_t row, size_t columns);

/**
* @brief Функция вставляет элемент в строку массива
* @param row - строка массива
* @param elem - элемент который надо вставить
* @param index - индекс после которго надо вставить элемент
* @param columns - количество столбцов
* @return Возвращает изменённую строку массива
*/
int* insert_to_row(const int* const row, size_t columns, int elem, size_t index);

/**
* @brief Функция вставляющая после всех столбцов, содержащих максимальный элемент столбец из нулей
* @param arr - массив
* @param row - количество строк
* @param columns - количество столбцов
* @return Возвращает изменённый массив
*/
int** insert_max(const int* const* const arr, size_t row, size_t columns);

/**
* @brief Функция выделяющая память под массив указателей
* @param row - размер массива
* @return Возвращает массив указателей
*/
int** init_array_of_ptrs(size_t row);

/**
* @brief Функция копирующая массив src в массив dst размера size
* @param size - размер массивов
* @param dst - массив назначения
* @param src - исходный массив
*/
void copy(int* dst, int* src, size_t size);

/**
* @brief Точка входа в программу
* @return Возврящает 0, если программа работает верно, иначе 1
*/
int main() {
    setlocale(LC_ALL, "RU");

    size_t row = get_size("Введите количество строк в массиве: ");
    size_t columns = get_size("Введите количество столбцов в массиве: ");

    int** arr = init_array(row, columns);
    fill_array(arr, row, columns);

    puts("Исходный массив:\n");
    print_array(arr, row, columns);
    int** first_arr = replace_max_in_each_row(arr, row, columns);

    puts("Первое задание:\n");
    print_array(first_arr, row, columns);
    int** second_arr = insert_max(arr, row, columns);

    puts("Второе задание:\n");
    print_array(second_arr, row, columns + 1);

    delete_array(arr, row);
    delete_array(first_arr, row);
    delete_array(second_arr, row);

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

int** init_array(const size_t row, const size_t columns)
{
    int** arr = (int**)malloc(row * sizeof(int*));
    if (arr == NULL)
    {
        perror("Невозможно выделить память под массив!\n");
    }
    for (size_t i = 0; i < row; ++i)
    {
        arr[i] = init_single_array(row);
    }
    return arr;
}

void fill_array(int** array, size_t row, size_t columns)
{
    puts("Как Вы хотите заполнить массив:\n");
    names_of_random_and_keyboard();
    enum random_or_keybord choice = get_value("Выберите нужный вариант: ");
    switch (choice)
    {
    case Keyboard:
        fill_keyboard(array, row, columns);
        break;
    case Random:
        fill_random(array, row, columns);
        break;
    default:
        perror("Неверный выбор!!\n");
    }
}

void fill_keyboard(int** array, size_t row, size_t columns)
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
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            int value = get_value("");
            if (value < minimum_limit || value > maximum_limit)
            {
                errno = EIO;
                perror("Ошибка ввода!\n");
                abort();
            }
            array[i][j] = value;
        }
    }
}

void fill_random(int** array, const size_t row, const size_t columns)
{
    const int minimum_limit = get_value("Введите нижнюю границу массива: ");
    const int maximum_limit = get_value("Введите верхнюю границу массива: ");
    unsigned int ttime = time(NULL);
    srand(ttime);
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            array[i][j] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
        }
    }
}

void print_array(const int* const* array, size_t row, size_t columns)
{
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            printf_s("%d\t", array[i][j]);
        }
        puts("\n");
    }
}

int get_value(const char* message)
{
    int value;
    printf_s("%s", message);
    int res = scanf_s("%d", &value);
    if (res != 1)
    {
        errno = EIO;
        perror("Неверное значение\n");
        abort();
    }
    return value;
}

void delete_array(int*** arr, size_t row)
{
    if (arr != NULL) {
        for (size_t i = 0; i < row; ++i)
        {
            if (arr[i] != NULL)
            {
                free(arr[i]);
            }
        }
        free(arr);
        arr = NULL;
    }
}

int find_max_in_row(int const* const row, size_t columns)
{
    int max = row[0];
    for (size_t i = 1; i < columns; ++i)
    {
        if (row[i] > max)
        {
            max = row[i];
        }
    }
    return max;
}

int** copy_array(const int* const* const arr, size_t row, size_t columns)
{
    int** new_arr = init_array(row, columns);
    for (size_t i = 0; i < row; ++i)
    {
        memcpy(new_arr[i], arr[i], columns * sizeof(int));
    }
    return new_arr;
}

int** replace_max_in_each_row(const int* const* const arr, size_t row, size_t columns)
{
    int** tmp = copy_array(arr, row, columns);
    for (size_t i = 0; i < row; ++i)
    {
        int max_in_string = find_max_in_row(tmp[i], columns);
        for (size_t j = 0; j < columns; ++j)
        {
            if (tmp[i][j] == max_in_string)
            {
                tmp[i][j] = -tmp[i][j];
            }
        }
    }
    return tmp;
}

int* init_single_array(size_t columns)
{
    int* array_string = malloc(columns * sizeof(int));
    if (array_string == NULL)
    {
        perror("Невозможно выделить память под массив!\n");
    }
    return array_string;
}

size_t find_last_max_column_index(const int* const* const arr, size_t row, size_t columns)
{
    int max = arr[0][0];
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            if (arr[i][j] >= max)
            {
                max = arr[i][j];
            }
        }
    }
    size_t column_index = 0;
    for (size_t i = 0; i < row; ++i)
    {
        for (size_t j = 0; j < columns; ++j)
        {
            if (arr[i][j] == max && j > column_index)
            {
                column_index = j;
            }
        }
    }
    return column_index;
}

int** init_array_of_ptrs(size_t row)
{
    int** ptr_array = (int**)malloc(row * sizeof(int*));
    if (ptr_array == NULL)
    {
        perror("Невозможно выделить память под массив!\n");
    }
    return ptr_array;
}

void copy(int* dst, int* src, size_t size)
{
    if (dst != NULL && src != NULL)
    {
        for (size_t i = 0; i < size; ++i)
        {
            dst[i] = src[i];
        }
    }
}

int* insert_to_row(const int* const row, size_t columns, int elem, size_t index)
{
    int* new_array_string = init_single_array(columns + 1);
    copy(new_array_string, row, index + 1);
    new_array_string[index + 1] = elem;
    copy(new_array_string + index + 2, row + index + 1, columns - index - 1);
    return new_array_string;
}

int** insert_max(const int* const* const arr, size_t row, size_t columns)
{
    int** new_arr = init_array_of_ptrs(row);
    size_t index = find_last_max_column_index(arr, row, columns);
    for (size_t i = 0; i < row; ++i) {
        new_arr[i] = insert_to_row(arr[i], columns, 0, index);
    }
    return new_arr;
}
