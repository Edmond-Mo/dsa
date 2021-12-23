#include <cstdio>
#include <algorithm>

/*
 * Worst and ave time complexity: O(n^2). Worst when reversed.
 * Best: O(n), when already sorted.
 * Auxiliary space: O(1)
 * Stable: Yes
 */
void bubbleSort(int a[], int n) {
    int sortedWall = n - 1;
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int j = 0; j < sortedWall; j++)
            if (a[j] > a[j + 1]) {
                std::swap(a[j], a[j + 1]);
                swapped = true;
            }
        sortedWall--;
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

    bubbleSort(a, 6);

    printArray(a, 6);
    return 0;
}
