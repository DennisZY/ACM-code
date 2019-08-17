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
const int N = 200010;
int h[N];
int Head[N], ver[N << 1], nxt[N << 1], w[N << 1], vis[N], deg[N], d[N];
int dp[N];
int tot;
int n, m;
void pre(int u) {
    vis[u] = 1;
    d[u] = 0;
    for (int i = Head[u]; i; i = nxt[i]) {
        int v = ver[i];
        if (!vis[v]) {
            pre(v);
            if (deg[v] == 1)d[u] += w[i];
            else d[u] += min(d[v], w[i]);
        }
    }
}
void dfs(int u) {
    vis[u] = 1;
    for (int i = Head[u]; i; i = nxt[i]) {
        int v = ver[i];
        if (!vis[v]) {
            if (deg[v] == 1)dp[v] = d[v] + w[i];
            else dp[v] = d[v] + min(w[i], dp[u] - min(d[u], w[i]));
            dfs(v);
        }
    }
}
void add(int x, int y, int z) {
    ver[++tot] = y;
    nxt[tot] = Head[x];
    w[tot] = z;
    Head[x] = tot;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t-- ) {
        tot = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            dp[i] = Head[i] = deg[i] = vis[i] = 0;
        }
        for (int i = 1; i < n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            add(x, y, z);
            add(y, x, z);
            deg[x]++;
            deg[y]++;
        }
        pre(1);
        dp[1] = d[1];
        for (int i = 1; i <= n; i++)vis[i] = 0;
        dfs(1);
        int ans = 0;
        for (int i = 1; i <= n; i++)if (ans < dp[i])ans = dp[i];
        printf("%d\n", ans);
    }
    return 0;

}
