#include <cstdio>
#include <algorithm>

int partition(int a[], int low, int high);

/*
 * Time complexity: Best and ave - O(n lg n).
 * Worst case - partition always pick the smallest or greatest
 * element as pivot. O(n^2).
 * Stable: Current implementation is NOT stable.
 */
void quickSort(int a[], int low, int high) {
    if (low < high) {
        // Pivot's index.
        // After the partition, elements to the left of pi 
        // is less than pivot whereas elements to the right
        // is greater than or equal to pivot.
        // In other words, the pivot is now in the right place
        // of sorted order.
        int pi = partition(a, low, high);

        // recursively sort the left and right partitions.
        quickSort(a, low, pi - 1);
        quickSort(a, pi + 1, high);
    }
}

int partition(int a[], int low, int high) {
    // typically, use random index as pivot
    int pivot = a[high];    // use last element as pivot
    int pi = low;           // partition index

    for (int i = low; i < high; i++) {
        if (a[i] < pivot) {
            std::swap(a[i], a[pi]);
            pi++;
        }
    }
    std::swap(a[pi], a[high]);

    return pi;
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] {4, 3, 9, 3, 7, 5};
    printArray(a, 6);

    quickSort(a, 0, 5);

    printArray(a, 6);
    return 0;
}
