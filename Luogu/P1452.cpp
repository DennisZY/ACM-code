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
    node(int _x = 0, int _y = 0) : x(_x), y(_y) {}
    node operator-(const node& tmp) const { return node(x - tmp.x, y - tmp.y); }
    bool operator<(const node& tmp) const { return x < tmp.x || (x == tmp.x && y < tmp.y); }
    int det(const node& tmp) { return x * tmp.y - y * tmp.x; }
} no[N], res[N];
int stk[N], used[N];
ll dis(const node& a, const node& b) {
    ll x = a.x - b.x, y = a.y - b.y;
    return x * x + y * y;
}
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &no[i].x, &no[i].y);
    }
    if (n == 2) {
        printf("%lld\n", dis(no[1], no[2]));
        return 0;
    } else if (n == 3) {
        ll ans = dis(no[1], no[2]);
        ans = max(ans, dis(no[2], no[3]));
        ans = max(ans, dis(no[3], no[1]));
        printf("%lld\n", ans);
        return 0;
    }
    sort(no + 1, no + n + 1);
    int tp = 0;
    stk[++tp] = 1;
    for (int i = 2; i <= n; i++) {
        while (tp >= 2 && (no[stk[tp]] - no[stk[tp - 1]]).det(no[i] - no[stk[tp]]) <= 0)
            used[stk[tp--]] = 0;
        used[stk[++tp] = i] = 1;
    }
    int tmp = tp;
    for (int i = n - 1; i >= 1; i--) {
        if (used[i]) continue;
        while (tp > tmp && (no[stk[tp]] - no[stk[tp - 1]]).det(no[i] - no[stk[tp]]) <= 0)
            used[stk[tp--]] = 0;
        used[stk[++tp] = i] = 1;
    }
    for (int i = 1; i <= tp; i++) {
        res[i] = no[stk[i]];
    }
    ll ans = 0;
    int j = 3;
    for (int i = 1; i < tp; i++) {
        while (abs((res[i + 1] - res[i]).det(res[j] - res[i + 1])) <
               abs((res[i + 1] - res[i]).det(res[j + 1] - res[i + 1])))
            j = (j == tp) ? 1 : j + 1;
        ans = max(dis(res[i], res[j]), ans);
        ans = max(dis(res[i + 1], res[j]), ans);
    }
    printf("%lld\n", ans);
    return 0;
}