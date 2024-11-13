// Name: Pushpa Gajar	Roll no: 23518	Batch: S1
// DSA Assignment 09 
// Implement Heap sort to sort given set of values using max or min heap. 

#include <iostream>
using namespace std;

class HeapSort {
public:
    // Function to heapify the subtree rooted at index i
    void heapify(int arr[], int n, int i) {
        int largest = i;  // Initialize largest as root
        int left = 2 * i + 1;  // Left child index
        int right = 2 * i + 2;  // Right child index

        // If left child is larger than root
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }

        // If right child is larger than root
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }

        // If largest is not root, swap them and continue heapifying
        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);  // Heapify the affected subtree
        }
    }

    // Main function to perform heap sort
    void heapSort(int arr[], int n) {
        // Build max heap
        for (int i = n / 2 - 1; i >= 0; i--) {
            heapify(arr, n, i);
        }

        // Extract elements one by one from the heap
        for (int i = n - 1; i > 0; i--) {
            // Move current root to the end (swap the root with the last element)
            swap(arr[0], arr[i]);

            // Call heapify on the reduced heap
            heapify(arr, i, 0);
        }
    }

    // Function to print the array
    void printArray(int arr[], int size) {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    HeapSort hs;
    hs.heapSort(arr, n);

    cout << "Sorted array: \n";
    hs.printArray(arr, n);

    return 0;
}