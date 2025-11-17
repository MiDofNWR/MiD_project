#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
 * @brief valid - cчитывает значение, введённое с клавиатуры, с проверкой ввода
 * @return считанное значение
 */

double valid(void);

/**
 * @brief Рассчитывает функцию по заданной формуле
 * @param x - значение аргумента функции
 * @return рассчитанное значение
*/

double result(const double x);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
*/

int main(void) {
    
    const double i = valid();
    const double j = valid();
    const double step = valid();
    
    for (float x = i; x <= j + DBL_EPSILON; x += step) {
        printf("x = %.2f y = %f\n", x, result(x));
    }
    return 0;
}

double valid(void) {
    double valid = 0;
    if (scanf("%lf", &valid) != 1) {
        printf("Error\n");
        exit(1);
    }
    return valid;
}

double result(double x) {
    return x - (1 / (3 + sin(3.6 * x)));
}
