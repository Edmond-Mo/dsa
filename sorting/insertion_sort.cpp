#include <cstdio>
#include <algorithm>

/*
 * Time complexity: O(n^2)
 * Auxiliary space: O(1)
 * Boundary cases: Worst case - reversed. Best - already/almost sorted.
 * Stable: Yes
 *
 * Insertion sort is used when number of elements is small. Or when
 * the array is already almost sorted.
 */
void insertionSort(int a[], int n) {
    // i start with 1 because first element is considered
    // sorted by itself
    // index less than i is the sorted partition
    for (int i = 1; i < n; i++) {
        int key = a[i];     // backup key and insert it into
                            // the right place
        // shift all elements in the sorted partition that
        // are greater than the key one place to the right
        int j = i - 1;      // j is the biggest sorted element
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];    // shift right
            j--;
        }
        a[j + 1] = key;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] {4, 3, 9, 3, 7, 5};
    printArray(a, 6);

    insertionSort(a, 6);

    printArray(a, 6);
    return 0;
}
