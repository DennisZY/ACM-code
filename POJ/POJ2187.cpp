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
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
const double PI = acos(-1.);
// mt19937 myrand(time(0));
const int N = 50010;
int n;
struct node {
    ll x, y;
    node(ll _x = 0, ll _y = 0) : x(_x), y(_y) {}
    node operator-(const node& tmp) const { return node(x - tmp.x, y - tmp.y); }
    bool operator<(const node& tmp) const {
        if (x != tmp.x) return x < tmp.x;
        return y < tmp.y;
    }
    ll det(const node& tmp) const { return x * tmp.y - y * tmp.x; }
} no[N], res[N];
int stk[N], used[N];
ll dis(const node& a, const node& b) {
    ll x = a.x - b.x, y = a.y - b.y;
    return x * x + y * y;
}
ll cross(const node& a, const node& b, const node& c) {
    ll x1 = b.x - a.x, x2 = c.x - a.x, y1 = b.y - a.y, y2 = c.y - a.y;
    return x1 * y2 - y1 * x2;
}
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out2.txt", "w", stdout);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%lld%lld", &no[i].x, &no[i].y);
    }
    if (n == 2) {
        printf("%lld\n", dis(no[0], no[1]));
        return 0;
    }
    sort(no, no + n);
    int tp = 0;
    for (int i = 0; i < n; i++) {
        while (tp >= 2 && cross(no[stk[tp - 1]], no[stk[tp]], no[i]) <= 0) --tp;
        stk[++tp] = i;
    }
    int tmp = tp;
    for (int i = n - 2; i >= 0; i--) {
        while (tp > tmp && cross(no[stk[tp - 1]], no[stk[tp]], no[i]) <= 0) --tp;
        stk[++tp] = i;
    }
    for (int i = 1; i < tp; i++) {
        res[i] = no[stk[i]];
    }
    ll ans = 0;
    int j = 2;
    for (int i = 1; i < tp; i++) {
        while (cross(res[i], res[i + 1], res[j]) < cross(res[i], res[i + 1], res[j + 1]))
            j = j % tp + 1;
        ans = max(dis(res[i], res[j]), ans);
        ans = max(dis(res[i + 1], res[j]), ans);
    }
    printf("%lld\n", ans);
    return 0;
}
