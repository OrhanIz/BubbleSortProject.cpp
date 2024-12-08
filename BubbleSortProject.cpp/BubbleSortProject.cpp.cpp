#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include "benchmark.h"

// Bubble Sort - Classic
void bubbleSortClassic(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Bubble Sort - Reduced
void bubbleSortReduced(std::vector<int>& arr) {
    size_t n = arr.size();
    for (size_t i = 0; i < n - 1; ++i) {
        bool swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

// Bubble Sort - With Flag
void bubbleSortWithFlag(std::vector<int>& arr) {
    size_t n = arr.size();
    bool swapped = true;
    size_t i = 0;
    while (swapped) {
        swapped = false;
        for (size_t j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        ++i;
    }
}

// Function to generate datasets
std::vector<int> generateRandomData(size_t size) {
    std::vector<int> data(size);
    for (size_t i = 0; i < size; ++i) {
        data[i] = rand() % 10000;
    }
    return data;
}

std::vector<int> generateSortedData(size_t size) {
    std::vector<int> data(size);
    for (size_t i = 0; i < size; ++i) {
        data[i] = i;
    }
    return data;
}

std::vector<int> generateReverseSortedData(size_t size) {
    std::vector<int> data(size);
    for (size_t i = 0; i < size; ++i) {
        data[i] = size - i;
    }
    return data;
}

int main() {
    std::vector<size_t> sizes = { 5000, 10000, 20000, 30000, 40000, 50000, 60000 };

    for (auto size : sizes) {
        auto randomData = generateRandomData(size);
        auto sortedData = generateSortedData(size);
        auto reverseData = generateReverseSortedData(size);

        // Measure Classic Bubble Sort
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortClassic(randomData);
            std::cout << "Classic Bubble Sort (Random, " << size << "): " << b.elapsed() << " ms\n";
        }
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortClassic(sortedData);
            std::cout << "Classic Bubble Sort (Sorted, " << size << "): " << b.elapsed() << " ms\n";
        }
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortClassic(reverseData);
            std::cout << "Classic Bubble Sort (Reverse, " << size << "): " << b.elapsed() << " ms\n";
        }

        // Measure Reduced Bubble Sort
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortReduced(randomData);
            std::cout << "Reduced Bubble Sort (Random, " << size << "): " << b.elapsed() << " ms\n";
        }
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortReduced(sortedData);
            std::cout << "Reduced Bubble Sort (Sorted, " << size << "): " << b.elapsed() << " ms\n";
        }
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortReduced(reverseData);
            std::cout << "Reduced Bubble Sort (Reverse, " << size << "): " << b.elapsed() << " ms\n";
        }

        // Measure Bubble Sort With Flag
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortWithFlag(randomData);
            std::cout << "Bubble Sort With Flag (Random, " << size << "): " << b.elapsed() << " ms\n";
        }
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortWithFlag(sortedData);
            std::cout << "Bubble Sort With Flag (Sorted, " << size << "): " << b.elapsed() << " ms\n";
        }
        {
            Benchmark<std::chrono::milliseconds> b;
            bubbleSortWithFlag(reverseData);
            std::cout << "Bubble Sort With Flag (Reverse, " << size << "): " << b.elapsed() << " ms\n";
        }
    }
    return 0;
}
