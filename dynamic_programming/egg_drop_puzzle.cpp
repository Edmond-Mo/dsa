#include <cstdio>
#include <algorithm>
using namespace std;

int eggDrop(int n, int k) 
{
    // Minimum moves to test safe and highest floor level to 
    // drop egg from.
    // n: number of eggs available to test
    // k: number of floors to test
    int dp[n+1][k+1];
    // base case: 0 moves needed if #floor to test is zero
    for (int i = 0; i <= n; i++)
        dp[i][0] = 0;
    // base case: if only 1 egg available, need to test from floor
    // 1 up to floor k. ie, k moves
    for (int j = 0; j <= k; j++)
        dp[1][j] = j;
    
    // recurrence:
    // dp[n][k] = 1 + min{ max(dp[n-1][x-1], dp[n][k-x]) } for
    // all x = 1, 2, ..., k, where x is the floor number from
    // which we test drop an egg.
    //
    // If we drop an egg at floor x, two events happen:
    // 1. The egg breaks at floor x. It means that we'll test
    // with 1 less egg on with remaining floors at or below x - 1.
    // This reduce the state to be dp[n-1][x - 1].
    // 2. The egg doesn't break at floor x. It means that we'll test
    // again with same number of eggs, with floors above x, ie,
    // k - x.
    //
    // We do a max(case 1, case 2) to find worst case scenario.
    //
    // We iterate from floor 1 to k to find the minimum moves out
    // of all the worst cases.
    // 
    // i: num of eggs still available
    // j: num of consecutive floors remain to be tested
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int minMoves = 1e9;
            for (int dropAt = 1; dropAt <= j; dropAt++) {
                int curr = 1 + max(dp[i-1][dropAt-1], dp[i][j-dropAt]);
                if (curr < minMoves)
                    minMoves = curr;
            }
            dp[i][j] = minMoves;
        }
    }
    
    return dp[n][k];
}
    
int main()
{
    printf("Moves = %d\n", eggDrop(2, 10));
    return 0;
}

