#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <map>
#include <set>
/*
#include <unordered_map>
#include <unordered_set>
*/
using namespace std;
const int N = 110;
int n;
double x[N << 1], y[N << 1];
double w[N][N];
double a[N], b[N], delta, upd[N];
bool va[N], vb[N];
int match[N], ans[N];
bool dfs(int u) {
    va[u] = 1;
    for (int v = 1; v <= n; v++) {
        if (!vb[v]) {
            if (fabs(a[u] + b[v] - w[u][v]) <= 1e-6) {
                vb[v] = true;
                if (!match[v] || dfs(match[v])) {
                    match[v] = u;
                    return true;
                }
            } else {
                upd[v] = min(upd[v], a[u] + b[v] - w[u][v]);
            }
        }
    }
    return false;
}
void KM() {
    for (int i = 1; i <= n; i++) {
        a[i] = -(1 << 30);
        b[i] = 0;
        for (int j = 1; j <= n; j++) {
            a[i] = max(a[i], w[i][j]);
        }
    }
    for (int i = 1; i <= n; i++) {
        while (1) {
            memset(va, 0, sizeof va);
            memset(vb, 0, sizeof vb);
            delta = 1e10;
            for (int j = 1; j <= n; j++)upd[j] = 1e10;
            if (dfs(i))break;
            for (int j = 1; j <= n; j++)if (!vb[j])delta = min(delta, upd[j]);
            for (int j = 1; j <= n; j++) {
                if (va[j])a[j] -= delta;
                if (vb[j])b[j] += delta;
            }
        }
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n + n; i++) {
        scanf("%lf%lf", &x[i], &y[i]);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            double dx = x[i] - x[j + n], dy = y[i] - y[j + n];
            w[i][j] = -sqrt(dx * dx + dy * dy);
        }
    }
    KM();
    for (int i = 1; i <= n; i++) ans[match[i]] = i;
    for (int i = 1; i <= n; i++) printf("%d\n", ans[i]);
    return 0;
}