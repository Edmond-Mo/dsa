/*
 * Find element occurring once when all others are present thrice.
 *
 * Solution: Check each bit position. If at bit pos i, the count
 * of 1 bit is 3x + 1, then the singleton number has 1 at bit
 * pos i. Else it as bit 0 there. Construct the ans bit by bit.
 */
#include <cstdio>
#include <bitset>

int singleElement(int a[], int n) {
    unsigned int mask = 1;
    std::bitset<32> ans(0);
    for (int i = 0; i < 32; i++) {
        int count1 = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] & mask)
                count1++;
        }
        // if count1 is 0, -1%3==-1 != 0.
        // count1 = 1 is still equal to 3x+1
        if ((count1 - 1) % 3 == 0)
            ans[i] = 1;

        mask <<= 1;
    }

    return (int)ans.to_ulong();
}

int main() {
    //int a[] {2, 1, 1, 1, 4, 4, 4, 7, 7, 7};
    int a[] {1, 10, 1, 1};
    printf("%d\n", singleElement(a, sizeof(a)/sizeof(a[0])));
    return 0;
}
