#include <cstdio>

void merge(int a[], int low, int mid, int high);

/*
 * Time complexity: Best, ave, worst - O(n lg n).
 * Auxiliary space: O(n)
 * Stable: Yes, see comment below.
 *
 * Useful for sorting linked list. O(1) space.
 * Also used in external sorting.
 */
void mergeSort(int a[], int n, int low, int high) {
    // base case: either one element array (sorted by default)
    // or empty array (also sorted implicitly)
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;
    mergeSort(a, n, low, mid);
    mergeSort(a, n, mid + 1, high);
    merge(a, low, mid, high);
}

void merge(int a[], int low, int mid, int high) {
    // build left and right partition copies
    int leftSize = mid - low + 1;  // mid is inclusive to left part
    int rightSize = high - mid;    // mid is exclusive to right part
    int left[leftSize];
    int right[rightSize];
    for (int i = 0; i < leftSize; i++)
        left[i] = a[low + i];
    for (int i = 0; i < rightSize; i++)
        right[i] = a[mid + 1 + i];

    // Iteratively merge left & right partition into the original
    // array while selecting the smaller element from the front
    // of either one.
    int mi = low;   // merge index into the original array
    int li = 0;     // left partition index
    int ri = 0;     // right partition index
    while (li < leftSize && ri < rightSize) {
        // The '=' sign here is crtitcal! It will ensure the sort
        // is stable. Imagine both fronts are number 4. The left
        // partition's 4 occurs earlier in the original array.
        // Therefore we favors it by the '=' sign and put it
        // back first.
        if (left[li] <= right[ri]) {
            a[mi] = left[li];
            li++;
        }
        else {
            a[mi] = right[ri];
            ri++;
        }
        mi++;
    }

    // copy the remaining elements
    while (li < leftSize) {
        a[mi++] = left[li++];
    }
    while (ri < rightSize) {
        a[mi++] = right[ri++];
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

    mergeSort(a, 6, 0, 5);

    printArray(a, 6);
    return 0;
}
