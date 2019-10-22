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

const int N = 5010;
struct node {
    ll x, y;
    node(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    bool operator<(const node& tmp) const {
        if (x != tmp.x) return x < tmp.x;
        return y < tmp.y;
    }
    node operator-(const node& tmp) const { return node(x - tmp.x, y - tmp.y); }
    ll det(const node& tmp) const { return x * tmp.y - y * tmp.x; }
} no[N], res[N];
int stk[N], tp;
int used[N];
ll cal(const node& a, const node& b, const node& c) {
    ll x1 = b.x - a.x, x2 = c.x - a.x, y1 = b.y - a.y, y2 = c.y - a.y;
    return abs(x1 * y2 - y1 * x2);
}
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &no[i].x, &no[i].y);
    }
    sort(no + 1, no + n + 1);
    tp = 0;
    stk[++tp] = 1;
    for (int i = 2; i <= n; ++i) {
        while (tp >= 2 && (no[stk[tp]] - no[stk[tp - 1]]).det(no[i] - no[stk[tp]]) <= 0)
            used[stk[tp--]] = 0;
        used[i] = 1;
        stk[++tp] = i;
    }
    int tmp = tp;
    for (int i = n - 1; i > 0; --i) {
        if (!used[i]) {
            while (tp > tmp && (no[stk[tp]] - no[stk[tp - 1]]).det(no[i] - no[stk[tp]]) <= 0)
                used[stk[tp--]] = 0;
            used[i] = 1;
            stk[++tp] = i;
        }
    }
    for (int i = 1; i <= tp; i++) {
        res[i] = no[stk[i]];
    }
    ll ans = 0;
    for (int i = 1; i <= tp - 2; i++) {
        for (int j = i + 1, k = i + 2; j <= tp - 1; j++) {
            while (k + 1 <= tp && cal(res[i], res[j], res[k]) < cal(res[i], res[j], res[k + 1]))
                ++k;
            ans = max(ans, cal(res[i], res[j], res[k]));
        }
    }
    printf("%lld%s\n", ans / 2, (ans & 1) ? ".50000000" : ".00000000");
    return 0;
}