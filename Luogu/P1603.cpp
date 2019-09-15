#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
const double PI = acos(-1.);
// mt19937 myrand(time(0));

char str[][10] = {
    "one",      "two",      "three",   "four",    "five",      "six",
    "seven",    "eight",    "nine",    "ten",     "eleven",    "twelve",
    "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
    "nineteen", "twenty",   "a",       "both",    "another",   "first",
    "second",   "third",
};
int num[] = {
    1,  2,  3,  4,  5,  6,  7,  8, 9, 10, 11, 12, 13,
    14, 15, 16, 17, 18, 19, 20, 1, 2, 1,  1,  2,  3,
};
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    char s[10];
    int flag = 0;
    for (int i = 0; i < 6; i++) {
        scanf("%s", s);
        for (int j = 0; j <= 25; j++) {
            if (strcmp(s, str[j]) == 0) {
                if (!flag) {
                    printf("%d", num[j] * num[j] % 100);
                    flag = 1;
                } else {
                    printf("%.2d", num[j] * num[j] % 100);
                }
                break;
            }
        }
    }
    if (!flag) {
        puts("0");
    } else {
        puts("");
    }
    return 0;
}