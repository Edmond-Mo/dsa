// Reverse space separated sentence.

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

// straight C
void reverse1(char *str) {
    if (!str) return;
    int len = strlen(str);
    if (len <= 1)
        return;

    char *rev = (char *)malloc(sizeof(char) * (len + 1));
    if (!rev) return;
    char *wstart = str;
    char *wend = wstart;
    char *dst = rev + len;

    while (dst != rev) {
        while (*wend != '\0' && *wend != ' ') {
            wend++;
        }

        int wlen = wend - wstart;
        dst -= wlen;
        memcpy(dst, wstart, wlen);
        if (dst != rev)
            *--dst = ' ';
        wstart = wend + 1;
        wend = wstart;
    }

    memcpy(str, rev, len);
    free(rev);
/*
 * before while loop:
 * "AB_CD0"  -->  "000000" 
 *  s.....         r....d
 *  e.....
 *
 * "AB_CD0"  -->  "00_AB0" 
 *  s......        r.d...
 *  ..e....              
 *  ...s...
 *  ...e...
 *
 * "AB_CD0"  -->  "CD_AB0" 
 *  ...s...        r.d...
 *  .....e.        d.....
 */
}

// C++ using string class and vector
string reverse2(string str) {
    vector<string> stk;
    for (int i = 0; i < str.size(); i++) {
        int j = i + 1;
        while (j <= str.size()) { // == sign for checking null char
            if (str[j] == ' ' || str[j] == '\0') {
                string s = str.substr(i, j - i);
                //printf("pushing %s\n", s.c_str());
                stk.push_back(s);
                break;
            }
            j++;
        }
        i = j; //! i will increment by 1 by the for loop too!
    }

    string ans;
    for (int i = stk.size() - 1; i >= 0; i--) {
        //printf("%s\n", stk[i].c_str());
        ans += stk[i];
        if (i != 0)
            ans += " ";
    }
    return ans;

/*
 *  012345
 * "AB_CD0"   stk[] = { "AB", "CD" }
 *  i.....
 *  j.....
 *  ..j...
 *
 *  ...i..
 *  ....j.
 *  .....j
 *  ......i
 */
}

// Can we do it inplace? Yes
// 1) Reverse input string by characters
// 2) Reverse each space-separated word by char
// eg: "AB_CD0" -> "DC_BA0" -> "CD_AB0"
// or: "ABC_DEF0" -> "CBA_FED0" -> "FED_CBA"

void reverse_helper(char *start, char *end)
{
    if (!start || !end) return;
    end--;  // end was exclusive
    while (start <= end) {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
}

void reverse3(char *str) {
    if (!str) return;
    int len = strlen(str);
    if (len <= 1) return;

    reverse_helper(str, str + len);
    //printf("%s\n", str);
    int i = 0;
    while (i < len) {
        int j = i + 1;
        while (j <= len) {
            if (str[j] == ' ' || str[j] == '\0') {
                reverse_helper(str + i, str + j);
                break;
            }
            j++;
        }
        i = j + 1;
    }
}

int main() {
    char str[64] = "hello this is a c++ program!";

    printf("original:\n%s\n", str);
    reverse1(str);
    printf("reversed:\n%s\n", str);

    string orig(str);
    string r = reverse2(orig);
    printf("reversed:\n%s\n", r.c_str());

    char str3[64] = "hello this is a c program!";
    reverse3(str3);
    printf("reversed in place:\n%s\n", str3);
    return 0;
}
