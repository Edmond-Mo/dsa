/* Given a string composed of 0 and 1. Find the minimum splits such
 * that the substrings are binary representation of the power of 5
 * with no leading zeros.
 *
 * Power of 5:
 * 5^0: 1
 * 5^1: 101
 * 5^2: 11001
 * 5^3: 1111101
 *
 * Input: s = 1011011
 * Output: 3. 101, 101, 1
 *
 * Input: s = 0101
 * Output: -1. No leading zero allowed
 *
 * [Solution]:
 *
 * dp(i): min splits of string s[i..n-1] where n is length of str s.
 * Answer is dp(0).
 *
 * Base case:
 *      dp(i) = -1 if s[i] == 0, ie, leading zero
 *      dp(i) =  1 if s[i..n-1] is a power of 5.
 *
 * Recurrence:
 * 
 * Supposed we're looking at substring s[i...n-1]. We want to decide
 * where to 'cut' the substring into s[i..j], s[j+1...n-1] to
 * minimize the number of splits.
 * We iterate j = i to n - 1 (inclusive). For each iter, convert
 * s[i..j] into a number. If the number is a power of 5, we have
 * two options:
 *      1)  If j == n - 1, ie, j is end index.
 *          obviously, dp(i) = 1
 *      2)  Else, check dp(j + 1).
 *          if dp(j + 1) is -1, we dont have valid split, go next j.
 *          else, dp(i) = min(dp(i), dp(j + 1) + 1).
 *
 *          The "+1" is due to splitting into s[i..j], s[j+1..n-1].
 *
 * Example showing why the min() is required:
 *
 * Imagine we run the code until i = 0 and j = 0. We detect that
 * s[i..j] == 1 == power of 5.
 * Using recurrence formula,
 *      dp(0) = min(INF, dp(1) + 1) = 6
 *
 *  index  =  0    1    2    3    4    5    6    7
 *  ----------------------------------------------
 *      s  =  1    1    1    1    1    0    1    1
 *     dp  =  INF  5    4    3    2   -1    2    1
 *            i
 *            j
 *
 * It becomes:
 *  index  =  0    1    2    3    4    5    6    7
 *  ----------------------------------------------
 *      s  =  1    1    1    1    1    0    1    1
 *     dp  =  6    5    4    3    2   -1    2    1
 *            i
 *            j
 *
 * We continue to iterate j until j = 6:
 *  index  =  0    1    2    3    4    5    6    7
 *  ----------------------------------------------
 *      s  =  1    1    1    1    1    0    1    1
 *     dp  =  6    5    4    3    2   -1    2    1
 *            i
 *                                          j
 * 
 * But s[i..j] == 125 == 5^3.
 * Using recurrence,
 *      dp(0) = min(6, dp(7) + 1) = 2, giving us the split:
 *           1111101, 1
 */

#include <cstdio>
#include <cstdlib>
#include <climits>
#include <algorithm>
#include <cstring>

#define LIM 64
#define INF INT_MAX

typedef unsigned long long ull;
int dp[LIM];

inline bool isPowerOf5(ull val) {
    while (val > 1) {
        if (val % 5)
            return false;
        val /= 5;
    }
    return true;
}

void calcMinSplit(char s[], int n) {
    for (int i = n - 1; i >= 0; i--) {
        if (s[i] == '0') { // leading zero not allowed
            dp[i] = -1;
            continue;
        }

        ull val = 0;
        dp[i] = INF;
        for (int j = i; j < n; j++) {
            // calc value of s[i..j]
            // val(s[i..j]) = 2 * val(s[i..j-1]) + s[j]
            val = (val << 1) + (ull)(s[j] - '0');
            if (isPowerOf5(val)) {
                if (j == n - 1) {   // s[i..j] is power of 5
                    dp[i] = 1;
                }
                else if (dp[j + 1] != -1) {
                    dp[i] = std::min(dp[i], dp[j + 1] + 1);
                }
            }
        }

        if (dp[i] == INF) {
            dp[i] = -1;
        }
    }
}

int main() {
    char tests[][LIM] = {
        "0",
        "1",
        "01",
        "10",
        "101",
        "1011",
        "1010",
        "101101",
        "1010101",
        "11001",
        "1100111001",
        "1111101",
        "11111011",
    };

    for (int i = 0; i < sizeof(tests)/sizeof(tests[0]); i++) {
        calcMinSplit(tests[i], strlen(tests[i]));
        printf("[%16s]: ", tests[i]);
        for (int j = 0; j < strlen(tests[i]); j++)
            printf("%4d ", dp[j]);
        printf("\n");
    }

    return 0;
}
