#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>

void bubble_down(int a[], int n, int p);
void bubble_up(int a[], int n, int p);

/*
 * Time complexity: O(n lg n). Heap construction using our
 * fast method is actually O(n). Overall is still O(n lg n).
 * Auxiliary space: O(1)
 * Stable: Not stale in current implementation. To make it
 * stable, we can take the position of the elements into
 * consideration. Compare tuple as (value, pos) -
 *      (4, 4) > (4, 2)
 * Can use the same idea for quick sort.
 *
 * Also good for finding k largest elements of an array;
 * construc heap (linear time) then pop k times.
 * O(n + k lg n)
 *
 */
void heapSort(int a[], int n) {
    // First, use the 'fast' method to heapify the array
    // in place. 'Fast' means using the array content as is
    // and use the right half as the leaf nodes of the heap
    // tree. Then we just do a series of bubble down of
    // the internal nodes, starting from the bottomest.
    //
    // The 'slow' method is to insert array elements one
    // by one into the tree and do a bubble up each time.
    //
    // n / 2 - 1 is the bottom-most, right-most internal node
    // It's imperative to start from it because it ensures
    // that the sub-trees are already heapified before going
    // up to the higher-tier internal nodes.
    for (int i = n / 2 - 1; i >= 0; i--)
        bubble_down(a, n, i);

    // Now that we have an array arranged into a max heap,
    // we can pop the root node (maximum value remaining
    // in the tree) and put it at the BACK of the sorted
    // array to make a non-decreasingly sorted array.
    for (int heapSize = n - 1; heapSize > 0; heapSize--) {
        // 0: top of current max heap
        // heapSize: current front of sorted array
        std::swap(a[0], a[heapSize]);

        // After swapping the leaf node to the root,
        // bubble down from the root to make it a heap again.
        bubble_down(a, heapSize, 0);
    }
}

void bubble_down(int a[], int n, int p) {
    // building max heap
    int maxIdx = p;  // assume parent node is the max
    int left = 2 * p + 1;
    int right = 2 * p + 2;

    // find max node among parent, left child and right child
    if (left < n && a[left] > a[maxIdx])
        maxIdx = left;
    if (right < n && a[right] > a[maxIdx])
        maxIdx = right;

    // if parent is not the max node, swap its value with its
    // largest child and then recurse down using child node idx
    if (maxIdx != p) {
        std::swap(a[maxIdx], a[p]);
        bubble_down(a, n, maxIdx); // maxIdx is the largest child idx
    }
}

// for reference only
void bubble_up(int a[], int n, int p) {
    if (p == 0)     // root node
        return;
    int parent = (p - 1) / 2;
    if (a[p] > a[parent]) {
        std::swap(a[p], a[parent]);
        bubble_up(a, n, parent);
    }
}

// use STL priority_queue
void libHeapSort(int a[], int n) {
    // min heap (using std::greater<int>)
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(a[i]);
    }

    for (int i = 0; i < n; i++) {
        a[i] = pq.top(); pq.pop();
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] {4, 3, 9, 3, 7, 5, 4, 1, 2};
    printArray(a, 9);

    //libHeapSort(a, 9);
    heapSort(a, 9);

    printArray(a, 9);
    return 0;
}
