#include <cstdio>
#include <cmath>

int powMod(int b, int p, int m) {
    if (b == 0) return 0;
    if (p == 0) return 1;

    int ans;
    if (p % 2 == 0) {
        ans = powMod(b, p / 2, m);
        ans = (ans * ans) % m;
    }
    else {
// works fine, but below seems better/more readable
//        ans = b % m; // in case b > m; we keep ans = something % m
//                     // ie, ans < m, so we can't have ans = b > m.
//        ans = (ans * powMod(b, p - 1, m) % m) % m;

        ans = ((b % m) * (powMod(b, p - 1, m) % m)) % m; 
    }

    return (ans % m + m) % m; // in case ans is negative
}

int main() {
    printf("%d ^ %d = %d\n", 7, 9, (int)pow(7, 9));
    printf("%d ^ %d mod %d = %d\n", 7, 9, 8, powMod(7, 9, 8));
    return 0;
}
