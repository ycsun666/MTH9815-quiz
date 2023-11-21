// Question 2&3. Write a max-heap class with Add() and Remove() method

#include <iostream>
#include <vector>

template <typename T>
class MaxHeap {
private:
    std::vector<T> heap;

    void heapifyUp() {
        int index = heap.size() - 1;
        while (index > 0) {
            int parentIndex = (index - 1) / 2;
            if (heap[index] > heap[parentIndex]) {
                std::swap(heap[index], heap[parentIndex]);
                index = parentIndex;
            } else {
                break;
            }
        }
    }

    void heapifyDown() {
        int index = 0;
        int size = heap.size();
        while (index < size) {
            int leftChild = 2 * index + 1;
            int rightChild = 2 * index + 2;
            int largest = index;

            if (leftChild < size && heap[leftChild] > heap[largest]) {
                largest = leftChild;
            }

            if (rightChild < size && heap[rightChild] > heap[largest]) {
                largest = rightChild;
            }

            if (largest != index) {
                std::swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void Add(T value) {
        heap.push_back(value);
        heapifyUp();
    }

    T Remove() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        T max = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown();

        return max;
    }

    bool isEmpty() const {
        return heap.empty();
    }
};


int main() {
    MaxHeap<int> maxHeap;
    
    // add elements to maxHeap
    maxHeap.Add(3);
    maxHeap.Add(1);
    maxHeap.Add(4);
    maxHeap.Add(1);
    maxHeap.Add(10);
    maxHeap.Add(5);
    maxHeap.Add(15);
    maxHeap.Add(3);
    maxHeap.Add(8);

    // remove elements from maxHeap
    while (!maxHeap.isEmpty()) {
        std::cout << maxHeap.Remove() << " ";
    }
    std::cout << std::endl;

    return 0;
}
