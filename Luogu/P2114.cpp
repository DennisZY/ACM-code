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
const int N = 100010;
char op[5];
unsigned int t, n, m;
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    unsigned int x = 0, y = 0;
    y--;
    scanf("%u%u", &n, &m);
    for (unsigned int i = 1; i <= n; i++) {
        scanf("%s%u", op, &t);
        if (op[0] == 'A') {
            x &= t;
            y &= t;
        } else if (op[0] == 'O') {
            x |= t;
            y |= t;
        } else {
            x ^= t;
            y ^= t;
        }
    }
    unsigned int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (x >> i & 1)
            ans |= 1 << i;
        else if (y >> i & 1 && (1 << i) <= m) {
            ans |= 1 << i;
            m -= 1 << i;
        }
    }
    printf("%u\n", ans);
    return 0;
}