#include <iostream>
#include <cmath>
#include <omp.h>
#include <iomanip>

double f(double x) {
    return (exp(x) + 1.0) / (exp(x) + pow(x, 3.0));
}

int main() {
    double a = 0.0;
    double b = 2.0;
    double epsilon = 1e-5;
    double integral = 0.0;
    double prev_integral = 0.0;
    long long n = 1000; // Начальное количество подынтервалов
    int max_threads = omp_get_max_threads();

    std::cout << "Starting calculation with " << max_threads << " threads." << std::endl;
    std::cout << "Interval: [" << a << ", " << b << "], Precision: " << epsilon << std::endl;

    do {
        prev_integral = integral;
        integral = 0.0;
        double h = (b - a) / n;
        
#pragma omp parallel for reduction(+:integral)
        for (long long i = 1; i <= n; ++i) {
            double x = a + i * h;
            integral += f(x);
        }
        
        integral *= h;
        
        if (n > 100000000) { // Ограничение на количество итераций
            std::cout << "Warning: Number of intervals is very large. Exiting to prevent infinite loop." << std::endl;
            break;
        }

        n *= 2; // Удвоение количества подынтервалов для следующей итерации

    } while (std::abs(integral - prev_integral) > epsilon);

    std::cout << std::fixed << std::setprecision(6) << "Calculated integral: " << integral << std::endl;
    std::cout << "Final number of intervals: " << n / 2 << std::endl;

    return 0;
}
