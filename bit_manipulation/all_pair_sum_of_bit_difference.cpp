#include <cstdio>

/*
 * Given an integer array of n integers, find sum of bit
 * differences in all pairs that can be formed from array
 * elements.
 * Bit difference of a pair (x, y) is count of different
 * bits at same positions in binary representations of x and y.
 *
 * Linear solution:
 * Look at each bit position of all numbers. For each bit, count
 * the number of bit 1. Then the number of bit 0 is just n - count.
 *
 * For each bit, the number of bit difference is just:
 *      count * (n - count)
 *
 * Imagine, for each bit, arrange the numbers on two sides, with
 * numbers with bit 1 at the given bit pos on the left and bit 0
 * on the right.
 *
 * Considering bit 0:
 *
 * 001
 *          100
 * 101
 *          010
 * 011
 *
 * Obviously, since we're matching all numbers to all other numbers,
 * numbers on the left will all match with all numbers on the right.
 *
 * Numbers matching with numbers on the same side won't contribute
 * to bit difference. But numbers on the opposite side will. 
 *
 * The formula is obviously #right * #left.
 * And, since we match both way, the formula becomes:
 *      #r * #l * 2
 */

int sumBitDiff(unsigned int a[], int n) {
    int ans = 0;
    // assuming 32 bit integers
    unsigned int mask = 1;
    for (int i = 0; i < 32; i++) {
        int count1 = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] & mask)
                count1++;
        }
        ans += (count1 * (n - count1)) << 1;
        mask <<= 1;
    }
    return ans;
}

int main() {
    unsigned int a[] = {2, 4, 5, 9, 12, 6, 3};
    //unsigned int a[] = {1, 3, 5};
    printf("%d\n", sumBitDiff(a, sizeof(a)/sizeof(a[0])));
    return 0;
}

