#include <cstdio>
#include <vector>
#include <string>
using namespace std;

void generateParenthesis(int n, int open, int close, string s,
                         vector<string> &ans) {
    if (open == n && close == n) {
        ans.push_back(s);
        return;
    }

    if (open < n)
        generateParenthesis(n, open+1, close, s+"{", ans);

    if (close < open)
        generateParenthesis(n, open, close+1, s+"}", ans);
}

int main() {
    vector<string> v;
    for (int i = 1; i < 5; i++) {
        v.clear();
        generateParenthesis(i, 0, 0, "", v);
        printf("n = %d\n", i);
        for (auto s : v) {
            printf("%s\n", s.c_str());
        }
        printf("\n");
    }

    return 0;
}
