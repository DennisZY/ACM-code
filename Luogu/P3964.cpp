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
typedef unsigned long long ull;
const double PI = acos(-1.);
// mt19937 myrand(time(0));

const int N = 100010;
struct node {
    ll x, y;
} no[N];
ll xx[N], yy[N], sx[N], sy[N];

int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        ull x, y;
        scanf("%llu%llu", &x, &y);
        xx[i] = no[i].x = x + y;
        yy[i] = no[i].y = x - y;
    }
    sort(xx + 1, xx + n + 1);
    sort(yy + 1, yy + n + 1);
    sx[0] = sy[0] = 0;
    for (int i = 1; i <= n; i++) {
        sx[i] = sx[i - 1] + xx[i];
        sy[i] = sy[i - 1] + yy[i];
    }
    ull ans = 1ll << 62;
    for (int i = 1; i <= n; i++) {
        ull tmp = 0;
        int idx = lower_bound(xx + 1, xx + n + 1, no[i].x) - xx;
        int idy = lower_bound(yy + 1, yy + n + 1, no[i].y) - yy;
        tmp += sx[n] - sx[idx] - (n - idx) * no[i].x;
        tmp += idx * no[i].x - sx[idx];
        tmp += sy[n] - sy[idy] - (n - idy) * no[i].y;
        tmp += idy * no[i].y - sy[idy];
        if (tmp < ans) {
            ans = tmp;
        }
    }
    printf("%llu\n", ans / 2);
    return 0;
}
