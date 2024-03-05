#include <iostream>
#include <algorithm>
#include <cstdlib>

const int ROWS = 2;
const int COLS = 9;

void fillRandomArray(int arr[ROWS][COLS]) {
    // Filling the array with random values
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            arr[i][j] = std::rand() % 100;
        }
    }
}

void printArray(const int arr[ROWS][COLS]) {
    // Printing the array to the console
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << arr[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

int findMinEl(int arr[ROWS][COLS]) {
    std::cout << "Finding the row with the minimum element" << std::endl;

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
    std::cout << "Minimum element: " << minimal << std::endl;
    std::cout << "Index of the row with the minimum element: " << minIndex << std::endl;
    return minIndex;
}

void shellSort(int arr[ROWS][COLS], int row) {
    // Shell Sort implementation for the specified row of the 2D array
    for (int gap = COLS / 2; gap >= 1; gap /= 2) {
        for (int j = gap; j < COLS; j++) {
            // Iterate through the array elements with the given gap
            for (int i = j - gap; i >= 0; i -= gap) {
                // Compare and swap elements with a gap
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

int main() {
    setlocale(LC_ALL, "Ukrainian");
    std::srand(std::time(0));

    int array[ROWS][COLS];

    fillRandomArray(array);

    std::cout << "Initial array:" << std::endl;
    printArray(array);

    int minRowIndex = findMinEl(array);
    shellSort(array, minRowIndex);

    std::cout << "\nShell Sort" << std::endl;
    printArray(array);

    return 0;
}
