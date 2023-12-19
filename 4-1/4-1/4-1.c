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
* @brief ������� ��������� ������ ���������, �������� ������� ������ 3
* @param size - ������ �������
* @param array - ������
*/
void print_indexes_3(const int* const arr, size_t size);

/**
* @brief ������� ��������� ��������� k ��������� ������� � �����������  �� �� ���������������
* @param size - ������ �������
* @param array - ������
* @return ��������� k ��������� ��������� �������
*/
int* replace_last_k(const int* const arr, size_t size);

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
* @brief ������� ����������� ���� � ����������
* @param size - ������ �������
* @param array - ������
*/
void fill_keyboard(const size_t size, int* array, int minimum_limit, int maximum_limit);

/**
* @brief ������� ����������� ������ ���������� �������
* @param size - ������ �������
* @param array - ������
* @param minimum_limit - ������� �����
* @param maximum_limit - ������� ������
*/
void fill_random(const size_t size, int* array, int minimum_limit, int maximum_limit);

/**
* @brief ������� ��������� ����������� ������
* @param size - ������ �������
* @param array - ������
*/
void print_array(const size_t size, const int* array);

/**
* @brief ������� ����������� � ����������� �������� �� ����
* @param message - ����� ��������� ��� ������������
* @return ��������
*/
int get_value(const char* message);

/**
* @brief ������� ����������� ������ ���� �� ���� �������� ��������� � ������, ������ ��������� �����
* @param size - ������ �������
* @param array - ������
* @param checkSum - ����� ������� ����� ��� �������� ��������
*/
bool is_coulple_sum(const size_t size, const int* array, int checkSum);

/**
* @brief ������� �������� ���� �� ���� �������
* @param size - ������ �������
* @param array - ������
*/
void print_couples(const size_t size, const int* array);

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
* @brief ������� ��������� ������ ���������� ������� ��� ������� � ���������� � ����������� �� ������ ������������
* @param size - ������ �������
* @param array - ������
* @param minimum_limit - ������� �����
* @param maximum_limit - ������� ������
*/
void fill_array(const size_t size, int* array, int minimum_limit, int maximum_limit);

bool checklimit(int minimum_limit, int maximum_limit);

/**
* @brief ����� ����� � ���������
* @return ���������� 0, ���� ��������� �������� �����, ����� 1
*/
int main()
{
    setlocale(LC_ALL, "RU");

    size_t size = get_size("������� ������ �������: ");
    int* arr = init_array(size);
    const int minimum_limit = get_value("������� ������ ������� �������: ");
    const int maximum_limit = get_value("������� ������� ������� �������: ");
    fill_array(size, arr, minimum_limit, maximum_limit);

    puts("�������� ������: \n");
    print_array(size, arr);

    print_array(size, replace_last_k(arr, size));

    print_indexes_3(arr, size);

    print_couples(size, arr);

    return 0;
}

void names_of_random_and_keyboard()
{
    printf_s("Keyboard - %d\n", (int)Keyboard);
    printf_s("Random - %d\n", (int)Random);
}

int* replace_last_k(const int* const arr, size_t size)
{
    size_t k = get_size("������� k: ");
    int* arr_k = init_array(size);
    memcpy(arr_k, arr, size * sizeof(int));
    for (size_t i = size; i < size; ++i)
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
        perror("�� ������� �������� ������ ��� ������!\n");
        abort();
    }
    return arr;
}

void fill_array(const size_t size, int* array, int minimum_limit, int maximum_limit)
{
    puts("��� �� ������ ��������� ������:\n");
    names_of_random_and_keyboard();
    enum random_or_keyboard choice = (enum random_or_keyboard)get_value("������� ������ �������: ");
    switch (choice) {
    case Keyboard:
        fill_keyboard(size, array, minimum_limit, maximum_limit);
        break;
    case Random:
        fill_random(size, array, minimum_limit, maximum_limit);
        break;
    default:
        perror("�������� �����!\n");
        abort();
    }
}

void fill_keyboard(const size_t size, int* array, int minimum_limit, int maximum_limit)
{
    if (checklimit(minimum_limit, maximum_limit))
    {
        errno = EIO;
        perror("�������� ������� �����");
        abort();
    }
    puts("������� �������: ");
    for (size_t i = 0; i < size; i++)
    {
        int c = get_value("");
        if (c < minimum_limit || c > maximum_limit)
        {
            errno = EIO;
            perror("�������� ��������");
            abort();
        }
        array[i] = c;
    }
}

void fill_random(const size_t size, int* array, int minimum_limit, int maximum_limit)
{
    unsigned int ttime = time(NULL);
    srand(ttime);
    for (size_t i = 0; i < size; i++)
    {
        array[i] = minimum_limit + rand() % (maximum_limit - minimum_limit + 1);
    }
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
        perror("������ �����");
        abort();
    }
    return a;
}

void print_indexes_3(const int* const arr, size_t size)
{
    puts("������� ���������, ������� 3:\n");
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

void print_couples(const size_t size, const int* array)
{
    int checkSum = get_value("������� ����� ���������: ");
    if (is_coulple_sum(size, array, checkSum))
    {
        puts("������������\n");
    }
    else
    {
        puts("�����������\n");
    }
}
bool checklimit(int minimum_limit, int maximum_limit)
{
    if (minimum_limit >= maximum_limit)
    {
        return false;
    }
    return true;
}