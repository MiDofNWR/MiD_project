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
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение аргумента функции
 * @return рассчитанное значение
*/

double result(double x);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
*/

int main(void) {
    
    double i = valid();
    double j = valid();
    double step = valid();
    
    for (float x = i ; x <= j + step ; x += step) {
        if (x <= DBL_EPSILON) {
            printf("x = %.2f y = не определено\n", x);
        }
        else {
            printf("x = %.2f y = %f\n", x, result(x));
        }
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
    return x - 3 + (1 / sin(3.6 * x));
}
