#include <iostream>
#include <vector>


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


    return 0;
}
