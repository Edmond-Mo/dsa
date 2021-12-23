#include <iostream>

int main() {
    int a[] {-5, -2, -5, -3, -4, -9, -2, -1, -4};
    
    int curr = 0;
    int best = -1e9; // -INF
    
    for (unsigned int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
        curr += a[i];
        // The follow two lines' order is important.
        // Currently, we return the least negative sum if all
        // elements of the array are negative. If reversed,
        // we'll return 0 as the best sum.
        best = std::max(best, curr);
        curr = std::max(curr, 0);
    }
    
    std::cout << best << "\n";

    return 0;
}

