#include <stdio.h>
#include <math.h>

/**
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */

const double a(const double x, const double y, const double z);

/**
 * @brief Рассчитывает функцию В по заданной формуле
 * @param x - значение параметра x
 * @param y - значение параметра y
 * @param z - значение параметра z
 * @return рассчитанное значение
 */
const double b(const double x, const double y, const double z);

/**
 * @brief Точка входа в программу
 * @return Возвращает 0, если программа выполнена корректно
 */

int main(void) {
    
    const double x = -4.8f;
    const double y = 17.5;
    const double z = 3.2;
    
    printf("x: %.1lf\ny: %.1lf\nz: %.1lf\n\na:%.1lf\nb:%.1lf\n", x, y, z, a(x, y, z), b(x, y, z));
    
    return 0;
}

const double a(const double x, const double y, const double z) {
    return (y * z * pow(x, 2)) - z / sin(pow(x/z, 2));
}

const double b(const double x, const double y, const double z) {
    return (z * exp(-sqrt(z)) * cos(y * x / z));
}
