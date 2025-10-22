#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/**
 * @brief valid - cчитывает значение, введённое с клавиатуры, с проверкой ввода
 * @return считанное значение
 */

double valid(void);

/**
 * @brief res2 - находит периметр прямоугольника
 * @param l - значение длинны
 * @param w - значение ширины
 * @return рассчитанное значение
 */

double rectangle(const double l, const double w);

/**
 * @brief triangle - находит периметр прямоугольника
 * @param a - значение первого числа
 * @param b - значение второго числа
 * @param c - значение второго числа
 * @return рассчитанное значение
 */

double triangle(const double a, const double b, const double c);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */

int main(void) {
    int choise = 1;
    while (choise != 0) {
        printf("Выберите фигуру для вычисления площади:\n1 - Прямоугольник\n2 - Треугольник\n0 - Выход\n");
        choise = valid();
        switch (choise) {
                
            case 0:
                printf("Выход из программы...\n");
                break;
                
            case 1:
                printf("Ваш выбор: пямоугольник\n");
                printf("Введите длинну:");
                double l = valid();
                printf("Введите ширину:");
                double w = valid();
                printf("Площадь: %lf\n\n", rectangle(l, w));
                break;
                
            case 2:
                printf("Ваш выбор: треугольник\n");
                printf("Введите первую сторону:");
                double a = valid();
                printf("Введите вторую сторону:");
                double b = valid();
                printf("Введите третью сторону:");
                double c = valid();
                printf("Площадь: %lf\n\n", triangle(a, b, c));
                break;
                
            default:
                printf("Неверней выбор\n");
                break;
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

double rectangle(const double l, const double w) {
    return l * w;
}


double triangle(const double a, const double b, const double c) {
    double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
}
