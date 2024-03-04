#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>
//TESTTTTT

const int ROWS = 2;
const int COLS = 9;

void fillRandomArray(int arr[ROWS][COLS]) {
    // Заповнення масиву випадковими значеннями
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = std::rand() % 100;
        }
    }
}

void printArray(const int arr[ROWS][COLS]) {
    // Виведення масиву на екран
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int findMinEl(int arr[ROWS][COLS]) {
    std::cout << "Знаходження рядка, що містить мінімальний елемент" << std::endl;

    int* minArr = new int[ROWS]; 

    for (int i = 0; i < ROWS; i++) {
        int min = arr[i][0];  

        for (int j = 0; j < COLS; j++) {
            std::cout << arr[i][j] << "\t";

            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }

        minArr[i] = min;  
        std::cout << std::endl;
    }

    int minimal = minArr[0];
    int minIndex = 0;
    for (int i = 1; i < ROWS; i++) {
        if (minArr[i] < minimal) {
            minimal = minArr[i];
            minIndex = i;
        }
    }

    delete[] minArr; 
    std::cout << "Мінімальний елемент: " << minimal << std::endl;
    std::cout << "Індекс рядка з мінімальним елементом: " << minIndex << std::endl;
    return minIndex;
}

void shellSort(int arr[ROWS][COLS], int row) {
    for (int gap = COLS / 2; gap >= 1; gap /= 2) {
        for (int j = gap; j < COLS; j++) {
            for (int i = j - gap; i >= 0; i -= gap) {
                if (arr[row][i + gap] > arr[row][i]) {
                    break;
                }
                else {
                    std::swap(arr[row][i + gap], arr[row][i]);
                }
            }
        }
    }
}

void heapSort() {
    std::cout << "Hello";
}

int main() {
    setlocale(LC_ALL, "Ukrainian");
    std::srand(std::time(0));

    int array[ROWS][COLS];

    fillRandomArray(array);

    std::cout << "Початковий масив:" << std::endl;
    printArray(array);

    int minRowIndex = findMinEl(array);
    shellSort(array, minRowIndex);

    std::cout << "\nМасив після сортування за зростанням рядка, що містить мінімальний елемент:" << std::endl;
    printArray(array);

    return 0;
}
