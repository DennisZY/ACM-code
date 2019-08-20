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
typedef long long ll;
const int N = 100010;
ll h[N];
int em[10], top;
int nxt[2][N];
int dp[20][N][2];
ll da[20][N][2], db[20][N][2];
int s[N], x[N];
set<pair<ll, int>>se;
set<pair<ll, int>>::iterator lt, rt, it;
int w;
void calc(int s, int x, ll &ca, ll &cb) {
    ca = cb = 0;
    int p = s;
    for (int i = w; i >= 0; i--) {
        if (dp[i][p][0] && ca + cb + da[i][p][0] + db[i][p][0] <= x) {
            ca += da[i][p][0];
            cb += db[i][p][0];
            p = dp[i][p][0];
        }
    }
}
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &h[i]);
    }
    for (int i = n; i; i--) {
        se.insert(make_pair(h[i], i));
        it = se.find(make_pair(h[i], i));
        rt = lt = it;
        top = 0;
        if (lt != se.begin())lt--, em[++top] = lt->second;
        if (lt != se.begin())lt--, em[++top] = lt->second;
        if (rt++, rt != se.end()) {
            em[++top] = rt->second;
            if (rt++, rt != se.end()) {
                em[++top] = rt->second;
            }
        }
        if (top >= 1) {
            ll minn = 0x3f3f3f3f3f3f3f3f;
            int id = 0;
            for (int j = 1; j <= top; j++) {
                if (abs(h[i] - h[em[j]]) < minn) {
                    minn = abs(h[i] - h[em[j]]);
                    id = j;
                } else if (abs(h[i] - h[em[j]]) == minn && h[em[id]] > h[em[j]]) {
                    id = j;
                }
            }
            nxt[1][i] = em[id];
            swap(em[id], em[top]);
            top--;
            if (top >= 1) {
                ll minn = 0x3f3f3f3f3f3f3f3f;
                int id = 0;
                for (int j = 1; j <= top; j++) {
                    if (abs(h[i] - h[em[j]]) < minn) {
                        minn = abs(h[i] - h[em[j]]);
                        id = j;
                    } else if (abs(h[i] - h[em[j]]) == minn && h[em[id]] > h[em[j]]) {
                        id = j;
                    }
                }
                nxt[0][i] = em[id];
            } else {
                nxt[0][i] = 0;
            }
        } else nxt[0][i] = nxt[1][i] = 0;
    }
    // for (int i = 1; i <= n; i++) {
    //     printf("%d %d\n", nxt[0][i], nxt[1][i]);
    // }
    for (int i = 1; i <= n; i++) {
        if (nxt[1][i])dp[0][i][1] = nxt[1][i], da[0][i][1] = 0, db[0][i][1] = abs(h[nxt[1][i]] - h[i]);
        if (nxt[0][i])dp[0][i][0] = nxt[0][i], da[0][i][0] = abs(h[nxt[0][i]] - h[i]), db[0][i][0] = 0;
    }
    w = (int)(log(n * 1.0) / log(2.0) + 0.001);
    for (int i = 1; i <= w; i++) {
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k <= 1; k++) {
                int l = (i == 1) ? k ^ 1 : k;
                if (dp[i - 1][j][k])dp[i][j][k] = dp[i - 1][dp[i - 1][j][k]][l];
                if (dp[i][j][k]) {
                    da[i][j][k] = da[i - 1][j][k] + da[i - 1][dp[i - 1][j][k]][l];
                    db[i][j][k] = db[i - 1][j][k] + db[i - 1][dp[i - 1][j][k]][l];
                }
            }
        }
    }
    scanf("%d", &x[0]);
    ll ansa = 1, ansb = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ll ca, cb;
        calc(i, x[0], ca, cb);
        if (cb == 0)ca = 1;
        if (ansa * cb > ansb * ca || (ansa * cb == ansb * ca && h[i] > h[ans])) {
            ansa = ca;
            ansb = cb;
            ans = i;
        }
    }
    printf("%d\n", ans);
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d", &s[i], &x[i]);
        ll ca, cb;
        calc(s[i], x[i], ca, cb);
        printf("%lld %lld\n", ca, cb);
    }
    return 0;
}