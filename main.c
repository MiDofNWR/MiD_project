#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

/**
 * @brief valid - cчитывает значение, введённое с клавиатуры, с проверкой ввода
 * @return считанное значение
*/

double Valid(void);

/**
 * @brief Проверяет что переменная не меньше единицы
 * @param i - значение проверяемой переменной
*/

void CheckS(const int i);

/**
 * @brief Проверяет диапазон на корректност ввода
 * @param min - минимально возможный элемент массива
 * @param max - максимально возможный элемент массива
*/

void CheckMinMax(const int min, const int max);

/**
 * @brief Проверят корректно ли выделана память под массив
 * @param array - массив
*/

void Not0(const int * array);

/**
 * @brief Множество выборов
*/

enum { Choise1 = 1, Choise2 = 2, Task1 = 1, Task2 = 2, Task3 = 3};

/**
 * @brief Заполняет массив элементами, который пользователь вводит с клавиатуры, c учётом максимально и минимально возможного
 * @param array - массив
 * @param size - размер массива
 * @param min - минимально возможный элемент массива
 * @param max - максимально возможный элемент массива
*/

void ByHand(int * array, const size_t size, const int min, const int max);

/**
 * @brief Заполняет массив случайнами элементами, c учётом максимально и минимально возможного
 * @param array - массив
 * @param size - размер массива
 * @param min - минимально возможный элемент массива
 * @param max - максимально возможный элемент массива
*/

void Random(int * array, const size_t size, const int min, const int max);

/**
 * @brief Выводит все элементы массива на экран
 * @param array - массив
 * @param size - размер массива
*/

void PrintArray(const int * array, const size_t size);

/**
 * @brief Копирует все элементы массива в новый
 * @param array - массив
 * @param size - размер массива
 * @return Новый массив, идентичный старому
*/

int * CopyArray(const int * array, const size_t size);

/**
 * @brief Проверяет, лежит ли чсило в указанном диапазоне
 * @param input - значение проверяемой переменной
*/

void CheckValue(const int input, const int min, const int max);

/**
 * @brief Считает сумму отрицательных элементов массива
 * @param array - массив
 * @param size - размер массива
*/

void defTask1(const int * array, const size_t size);

/**
 * @brief Считает колличество элементов, значения которых положительны и не превосходят заданного числа А
 * @param array - массив
 * @param size - размер массива
*/

void defTask2(const int * array, const size_t size);

/**
 * @brief Находит номер последней пары соседних элементов с разными знаками
 * @param array - массив
 * @param size - размер массива
*/

void defTask3(const int * array, const size_t size);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
*/

int main(void) {
    printf("Введите размер массива: ");
    const int size = Valid();
    CheckS(size);
    
    int * array = calloc(size,sizeof(int));
    Not0(array);
    
    printf("Введите диапазон массива: \n");
    const int min = Valid();
    const int max = Valid();
    CheckMinMax(min, max);
    printf("Диапазон массива: [%d,%d]\n", min, max);
    
    printf("\nЗаполнение массива:\n1 - Ручной ввод\n2 - Автоматический ввод\n");
    int choise = Valid();
    
    switch (choise)
    {
    case Choise1:
        ByHand(array, size, min, max);
        break;

    case Choise2:
        Random(array, size, min, max);
        break;

    default:
        fprintf(stderr,"Error\n");
        free(array);
        exit(1);
    }
    
    PrintArray(array, size);
    int * copyA = CopyArray(array, size);
    Not0(copyA);
    
    printf("\nВыбор действия:\n%d - Найти сумму отрицательных элементов\n%d - Найти количество тех элементов, значения которых положительны и не превосходят заданного числа А\n%d - Найти номер последней пары соседних элементов с разными знаками.\n", Task1, Task2, Task3);
    int choise2 = Valid();

    switch (choise2) {
    case Task1:
        defTask1(copyA, size);
        break;
            
    case Task2:
        defTask2(copyA, size);
        break;

    case Task3:
        defTask3(copyA, size);
        break;

    default:
        fprintf(stderr,"Error\n");
        free(array);
        free(copyA);
        exit(1);
    }

    free(array);
    free(copyA);

    return 0;
}

double Valid(void) {
    double valid = 0;
    if (scanf("%lf", &valid) != 1) {
        fprintf(stderr,"Error\n");
        exit(1);
    }
    return valid;
}

void CheckS(const int input) {
    if (input < 1) {
        fprintf(stderr,"Error\nЧисло должно быть не меньше 1\n");
        exit(1);
    }
}

void CheckMinMax(const int min, const int max)
{
    if (min >= max)
    {
        fprintf(stderr,"Error\nДиапазон указан неправильно\n");
        exit(1);
    }
}

void Not0(const int * array) {
    if (array == NULL) {
        fprintf(stderr,"Memory Error\n");
        exit(1);
    }
}

void Random(int * array, const size_t size, const int min, const int max) {
    
    Not0(array);
    
    srand((unsigned int)time(NULL));

    for (size_t i = 0; i < size; i++)
    {
        int numm = (rand() % (max - min + 1)) + min;
        array[i] = numm;
    }
}

void ByHand(int * array, const size_t size, const int min, const int max) {
    
    Not0(array);
    
    printf("\nВведи %zu элемент-а(ов) массива:\n", size);
    for (size_t i = 0; i < size; i++) {
        int num = Valid();
        CheckValue(num, min, max);
        printf("A[%zu] = %d\n", i, num);
        array[i] = num;
    }
}

void PrintArray(const int * array, const size_t size) {
    
    Not0(array);
    
    printf("\nВведённый массив: ");
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int * CopyArray(const int* array, const size_t size) {
    
    Not0(array);
    
    int * copyArr = calloc(size,sizeof(int));
    
    Not0(copyArr);
    
    for (size_t i = 0; i < size; i++) {
        copyArr[i] = array[i];
    }
    return copyArr;
}

void CheckValue(const int input, const int min, const int max) {
    if (input > max || input < min)
    {
        fprintf(stderr,"Error\nЧисло должно лежать в промежутке [%d;%d]\n", min, max);
        exit(1);
    }
}


void defTask1(const int * array, const size_t size) {
    
    Not0(array);
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] < 0) {
            sum += array[i];
        }
    }
    if (sum == 0) {
        printf("Отрицательных элементов в масиве нет\n");
        exit(0);
    }
    printf("Сумма отрицательных элементов: %d\n", sum);
}

void defTask2(const int *  array, const size_t size) {
    
    Not0(array);
    
    printf("Введите значение A: ");
    const int A = Valid();
    int count = 0;
    
    for (int i = 0; i < size; i++) {
        if ((array[i] < 0) && (array[i] <= A)) {
            count++;
        }
    }
    if (count == 0) {
        printf("Элементов, значения которых положительны и не превосходят заданного числа А в масиве нет\n");
        exit(0);
    }
    printf("Колличество элементов, значения которых положительны и не превосходят заданного числа А: %d\n", count);
}

void defTask3(const int * array, const size_t size) {
    
    Not0(array);
    
    int np = 0;
    
    for (int i = 0; i < size - 1; i++) {
        int a = array[i];
        int b = array[i + 1];
        if (((a > -1) && (b <= -1)) || ((a <= -1) && (b > -1))) {
            np = i + 1;
        }
    }
    if (np == 0) {
        printf("Соседних пар элементов с разными знаками в масиве нет\n");
        exit(0);
    }
    printf("Номер последней пары соседних элементов с разными знаками: %d\n", np);
}
