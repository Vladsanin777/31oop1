#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <cmath>
#include <iomanip>

// Мьютекс для защиты доступа к общим данным
std::mutex mtx;

// Структура для передачи данных в поток и получения результата
struct ThreadData {
    double x;
    double result;
};

// Функция для вычисления факториала
double factorial(int n) {
    if (n < 0) return 0;
    if (n == 0) return 1;
    double res = 1.0;
    for (int i = 1; i <= n; ++i) {
        res *= i;
    }
    return res;
}

// ----------------------------------------------------
// Функции вычисления рядов
// ----------------------------------------------------

double calculate_cos(double x, double epsilon = 1e-6) {
    double sum = 0.0;
    double term = 1.0;
    int n = 0;
    while (std::abs(term) > epsilon) {
        sum += term;
        n++;
        term = -term * x * x / ((2 * n - 1) * (2 * n));
    }
    return sum;
}

double calculate_sinh(double x, double epsilon = 1e-6) {
    double sum = 0.0;
    double term = x;
    int n = 0;
    while (std::abs(term) > epsilon) {
        sum += term;
        n++;
        term = term * x * x / ((2 * n) * (2 * n + 1));
    }
    return sum;
}

double calculate_sin(double x, double epsilon = 1e-6) {
    double sum = 0.0;
    double term = x;
    int n = 0;
    while (std::abs(term) > epsilon) {
        sum += term;
        n++;
        term = -term * x * x / ((2 * n) * (2 * n + 1));
    }
    return sum;
}

// ----------------------------------------------------
// Точки входа для потоков
// ----------------------------------------------------

void thread_cos(ThreadData* data) {
    double result = calculate_cos(data->x);
    // Защита доступа к данным с помощью мьютекса
    std::lock_guard<std::mutex> lock(mtx);
    data->result = result;
}

void thread_sinh(ThreadData* data) {
    double result = calculate_sinh(data->x);
    // Защита доступа к данным с помощью мьютекса
    std::lock_guard<std::mutex> lock(mtx);
    data->result = result;
}

void thread_cot(ThreadData* data) {
    double cos_val = calculate_cos(data->x);
    double sin_val = calculate_sin(data->x);
    double result = cos_val / sin_val;
    // Защита доступа к данным с помощью мьютекса
    std::lock_guard<std::mutex> lock(mtx);
    data->result = result;
}

int main() {
    // Создаем структуры для передачи данных
    ThreadData data_cos, data_sinh, data_cot;
    double x = 1.57; // Пример значения x

    data_cos.x = x;
    data_sinh.x = x;
    data_cot.x = x;

    // Создаем три потока с различными точками входа
    std::thread t_cos(thread_cos, &data_cos);
    std::thread t_sinh(thread_sinh, &data_sinh);
    std::thread t_cot(thread_cot, &data_cot);

    // Ожидаем завершения всех потоков
    t_cos.join();
    t_sinh.join();
    t_cot.join();

    // Выводим результаты
    std::cout << "Результаты вычислений для x = " << x << ":" << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    std::cout << "1. cos(" << x << ") = " << std::setprecision(10) << data_cos.result << std::endl;
    std::cout << "   Проверка (std::cos) = " << std::setprecision(10) << std::cos(x) << std::endl;
    std::cout << std::endl;

    std::cout << "2. sinh(" << x << ") = " << std::setprecision(10) << data_sinh.result << std::endl;
    std::cout << "   Проверка (std::sinh) = " << std::setprecision(10) << std::sinh(x) << std::endl;
    std::cout << std::endl;

    std::cout << "3. ctg(" << x << ") = " << std::setprecision(10) << data_cot.result << std::endl;
    std::cout << "   Проверка (1.0 / std::tan) = " << std::setprecision(10) << 1.0 / std::tan(x) << std::endl;
    
    return 0;
}
