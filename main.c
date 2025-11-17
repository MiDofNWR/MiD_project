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
 * @brief triangle - находит периметр треугольника
 * @param a - значение первой стороны
 * @param b - значение второй стороны
 * @param c - значение третей стороны
 * @return рассчитанное значение
 */

double triangle(const double a, const double b, const double c);

/**
 * @brief Множество выборов
 */

enum {rectangleChoice = 1, triangleChoice = 2};

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */

int main(void) {
    printf("Выберите фигуру для вычисления площади:\n1 - Прямоугольник\n2 - Треугольник\n");
    int choice = (int) valid();
    switch (choice) {
        case rectangleChoice:
            printf("Ваш выбор: пямоугольник\n");
            printf("Введите длинну:");
            const double l = valid();
            printf("Введите ширину:");
            const double w = valid();
            printf("Площадь: %lf\n\n", rectangle(l, w));
            break;
                
        case triangleChoice:
            printf("Ваш выбор: треугольник\n");
            printf("Введите первую сторону:");
            const double a = valid();
            printf("Введите вторую сторону:");
            const double b = valid();
            printf("Введите третью сторону:");
            const double c = valid();
            printf("Площадь: %lf\n\n", triangle(a, b, c));
            break;
                
        default:
            printf("Неверней выбор\n");
            break;
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
    if ((l > 0) && (w > 0)) {
        return l * w;
    }
    else {
        printf("Error\n");
        exit(1);
    }
}


double triangle(const double a, const double b, const double c) {
    if ((a > 0) && (b > 0) && (c > 0)) {
        double p = (a + b + c) / 2;
            return sqrt(p * (p - a) * (p - b) * (p - c));
    }
    else {
        printf("Error\n");
        exit(1);
    }
}
