#include <cstdio>
// for std::swap
#include <algorithm>

/*
 * Time complexity: O(n^2)
 * Auxiliary space: O(1)
 * Stability: Default implementation is unstable due to the swap.
 * The swap can move a duplicate element to the back and change
 * the order of the duplicated elements.
 *
 * Selection sort never makes more than O(n) swaps so it
 * can be useful when memory write is costly.
 */
void selectionSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx])
                minIdx = j;
        std::swap(a[i], a[minIdx]);
    }
}

/*
 * Time complexity: O(n^2)
 * Auxiliary space: O(1)
 * Stability: Stable. We maintain the elements' order by shifting
 * elements to the right one-by-one and put the min element in
 * front.
 */
void stableSelectionSort(int a[], int n) {
    for (int i = 0; i < n; i++) {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
            if (a[j] < a[minIdx])
                minIdx = j;
        int key = a[minIdx];
        while (minIdx > i) {
            a[minIdx] = a[minIdx - 1]; // shift right
            minIdx--;
        }
        a[i] = key; // place min element in front of shifted elements
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

    //selectionSort(a, 6);
    stableSelectionSort(a, 6);

    printArray(a, 6);
    return 0;
}
