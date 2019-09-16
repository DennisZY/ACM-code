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
string ch[10] = {
    "-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ",
    "-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-",
};
const int N = 265;
char s[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int k;
    scanf("%d%s", &k, s);
    int len = strlen(s);
    for (int i = 0; i <= 6; i++) {
        if (i == 2 || i == 5)
            continue;
        else if (i == 0 || i == 3 || i == 6) {
            for (int j = 0; j < len; j++) {
                putchar(' ');
                for (int z = 0; z < k; z++)
                    putchar(ch[s[j] - '0'][i]);
                putchar(' ');
                if (j != len - 1)
                    putchar(' ');
                else
                    putchar('\n');
            }
        } else {
            for (int ext = 0; ext < k; ext++) {
                for (int j = 0; j < len; j++) {
                    putchar(ch[s[j] - '0'][i]);
                    for (int z = 0; z < k; z++)
                        putchar(' ');
                    putchar(ch[s[j] - '0'][i + 1]);
                    if (j != len - 1)
                        putchar(' ');
                    else
                        putchar('\n');
                }
            }
        }
    }
    return 0;
}