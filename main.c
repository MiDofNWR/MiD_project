#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
 * @brief Рассчитывает значение первой функции
 * @param a - значение параметра a
 * @param x - значение параметра x
 * @return Рассчитанное значение
*/

double res1(const double a, const double x);

/**
 * @brief Рассчитывает значение второй функции
 * @param a - значение параметра a
 * @param x - значение параметра x
 * @return Рассчитанное значение
*/

double res2(const double a, const double x);

/**
 * @brief Проверяет переменную на условие
 * @param x - значение проверяемой переменной
 * @return 0 если условие ложно, иначе 1
*/

_Bool checkX(const double x);

/**
 * @brief valid - cчитывает значение, введённое с клавиатуры, с проверкой ввода
 * @return считанное значение
*/

double valid(void);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
*/

int main(void) {
    const double a = 1.5;
    printf("Введи число x: ");
    double x = valid();
    
    if (checkX(x)) {
        if (x < 4) {
            printf("y = %.6lf\n", res1(a, x));
        }
        else {
            printf("y = %.6lf\n", res2(a, x));
        }
    }
    else {
        printf("Функция не определена\n");
    }
    return 0;
}

double res1(const double a, const double x) {
    return a / x + pow(x, 2);
}

double res2(const double a, const double x) {
    return a * x + pow(x, 3);
}

_Bool checkX(const double x) {
  return (x != 0);
}

double valid(void) {
    double valid = 0;
    if (scanf("%lf", &valid) != 1) {
        printf("Error\n");
        exit(1);
    }
    return valid;
}
