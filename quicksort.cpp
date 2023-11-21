// question1. Write a quicksort algorithm to sort an array of integers

#include <iostream>

void print(const int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 7;
    int numbers[size] = {3, 2, 5, 1, 4, 7, 6};
    
    std::cout << "Before sorting: ";
    print(numbers, size);

    quickSort(numbers, 0, size - 1);
    std::cout << "After sorting: ";
    print(numbers, size);

    return 0;
}