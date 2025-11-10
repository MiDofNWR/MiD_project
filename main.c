#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief res1 - находит среднее арифметическое кубов чисел;
 * @param a - значение первого числа
 * @param b - значение второго числа
 * @return рассчитанное значение
 */

const double res1(const double a, const double b);

/**
 * @brief res2 - находит среднее геометрическое модулей чисел.;
 * @param a - значение первого числа
 * @param b - значение второго числа
 * @return рассчитанное значение
 */

const double res2(const double a, const double b);

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
    
    const double a = valid(), b = valid();
    
    printf("%lf\n%lf\n", res1(a, b), res2(a, b));
        
    return 0;
}



const double res1(const double a, const double b) {
    return (pow(a, 3) + pow(b, 3)) / 2;
}

const double res2(const double a, const double b) {
    return sqrt(fabs(a) * fabs(b));
}

double valid(void) {
    double valid = 0;
    if (scanf("%lf", &valid) != 1) {
        printf("Error\n");
        exit(1);
    }
    return valid;
}
