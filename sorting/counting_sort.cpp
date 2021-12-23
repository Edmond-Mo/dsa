#include <cstdio>

#define RANGE 255

/*
 * Time complexity: O(n + k), where n is number of elements in the
 * array and k is the numeric range of each element.
 * If k == O(n), then overall is O(n).
 * Auxiliary space: O(n + k)
 * Stable: Yes if implemented in the current way (see comment below).
 *
 * If the elements have negative number, we can find the minimum
 * negative number, say, -5, and use count[x - (-5)] to compensate.
 */
void countingSort(int a[], int n) {
    int count[RANGE + 1] = {0}; // init to all zeros
    // first, count all array elements
    for (int i = 0; i < n; i++)
        count[a[i]]++;

    // next, update count to be counts of elements
    // less than or equal to a[i]
    //
    // eg, if count[4] == 3, it means there are 3 elements in the
    // array with value less than or equal to 4.
    // then, for element 4, it can be placed in the output sorted
    // array index 3 - 1 = 2.
    for (int i = 1; i <= RANGE; i++)
        count[i] += count[i - 1];

    int sorted[n];
    // we start with index n - 1 to maintain stable order of the
    // sorted array
    for (int i = n - 1; i >= 0; i--) {
        sorted[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }

    for (int i = 0; i < n; i++)
        a[i] = sorted[i];
}


void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] {4, 3, 9, 3, 7, 5, 4};
    printArray(a, 7);

    countingSort(a, 7);

    printArray(a, 7);
    return 0;
}
