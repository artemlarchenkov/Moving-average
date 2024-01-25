#include <iostream>
#include <vector>
#include <chrono>

template <typename T>
std::vector<T> simpleMovingAverage(const std::vector<T>& data, int windowSize) {
    std::vector<T> result;
    double sum = 0.0;

    // Скользящее среднее для начального окна
    for (int i = 0; i < windowSize; ++i) {
        sum += data[i];
        result.push_back(sum / (windowSize));
    }

    //  Скользящее среднее для остальных данных
    for (int i = windowSize; i < data.size(); ++i) {
        sum = sum + data[i] - data[i - windowSize];
        result.push_back(sum / windowSize);
    }

    return result;
}
int main() {
    // Генерация случайных данных
    srand(time(0));
    std::vector<float> data;
    for (int i = 0; i < 1000000; ++i) {
        data.push_back(rand() % 100);
    }

    // Тестирование функции
    int windowSizes[] = {4, 8, 16, 32, 64, 128};
    for (int windowSize : windowSizes) {

        auto start = std::chrono::high_resolution_clock::now();
        auto result = simpleMovingAverage(data, windowSize); // Выполнение функции
        auto end = std::chrono::high_resolution_clock::now(); // Конец операции
        std::chrono::duration<double> duration = end - start; // Разница во времени между началом и концом

        // Вычисление отсчетов в секунду 
        double samplesPerSecond = static_cast<double>(data.size()) / duration.count();

        std::cout << "Window Size: " << windowSize << ", Duration: " << duration.count() << " seconds, Samples per Second: " << samplesPerSecond << "\n";
    }

    return 0;
}
