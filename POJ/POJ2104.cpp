#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
/*
#include <unordered_map>
#include <unordered_set>
*/
using namespace std;
const int N = 100005;
const int INF = 0x3f3f3f3f;
struct rec {
    int op, x, y, z;
} q[N << 1], lq[N << 1], rq[N << 1];
int ans[5010];
int c[N];
int n, m;
void add(int x, int y) {
    while (x <= n) {
        c[x] += y;
        x += x & (-x);
    }
}
int query(int x) {
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= x & (-x);
    }
    return ans;
}
void solve(int lval, int rval, int st, int ed) {
    if (st > ed)return ;
    if (lval == rval) {
        for (int i = st; i <= ed; i++) {
            if (q[i].op > 0) {
                ans[q[i].op] = lval;
            }
        }
        return ;
    }
    int mid = (lval + rval) >> 1;
    int lt = 0, rt = 0;
    for (int i = st; i <= ed; i++) {
        if (q[i].op == 0) {
            if (q[i].y <= mid) {
                add(q[i].x, 1);
                lq[++lt] = q[i];
            } else {
                rq[++rt] = q[i];
            }
        } else {
            int t = query(q[i].y) - query(q[i].x - 1);
            if (t >= q[i].z)lq[++lt] = q[i];
            else {
                q[i].z -= t;
                rq[++rt] = q[i];
            }
        }
    }
    for (int i = st; i <= ed; i++) {
        if (q[i].op == 0) {
            if (q[i].y <= mid) {
                add(q[i].x, -1);
            }
        }
    }
    for (int i = 1; i <= lt; i++)q[i + st - 1] = lq[i];
    for (int i = 1; i <= rt; i++)q[st - 1 + lt + i] = rq[i];
    solve(lval, mid, st, st + lt - 1);
    solve(mid + 1, rval, st + lt, ed);
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1, val; i <= n; i++) {
        scanf("%d", &val);
        q[++t].op = 0, q[t].x = i, q[t].y = val;
    }
    for (int i = 1; i <= m; i++) {
        q[++t].op = i;
        scanf("%d%d%d", &q[t].x, &q[t].y, &q[t].z);
    }
    solve(-INF, INF, 1, t);
    for (int i = 1; i <= m; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}