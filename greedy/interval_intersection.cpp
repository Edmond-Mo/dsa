#include <iostream>
// for pair
#include <utility>
// for sort
#include <algorithm>

std::pair<int,int> maxIntersection(int left[], int right[], int n) {
    std::pair<int,int> interval[n<<1];
    for (int i = 0; i < n; i++) {
        interval[i].first = left[i];
        interval[i].second = 1;
    }
    for (int i = 0; i < n; i++) {
        // add 1 because the right/closing bracket is inclusive, ie,
        // we still consider a point is within the interval at the
        // site of the closing bracket.
        interval[n + i].first = right[i] + 1;
        interval[n + i].second = -1;
    }

    n <<= 1;
    // sort is done lexicographically
    std::sort(interval, interval + n);

//    for (int i = 0; i < n; i++) {
//        std::cout << "(" << interval[i].first << ", " << interval[i].second << ")\n";
//    }

    std::pair<int, int> best(0, 0);   // (maxIntersect, point)
    int curr = 0;
    for (int i = 0; i < n; i++) {
        curr += interval[i].second;
        if (curr > best.first) {
            best.first = curr;
            best.second = interval[i].first;
        }
    }

    return best;
}

int main() {
    int l[] {1, 3, 5};
    int r[] {3, 4, 9};

    std::pair<int,int> ans = maxIntersection(l, r, 3);
    std::cout << "Max:" << ans.first << " point:" << ans.second << "\n";
    return 0;
}
