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
const int N = 10006;
int Head[N], ver[N << 1], nxt[N << 1], c[N << 1];
int a[N], fa[N], d[N], cnt[N], s[N];
bool vis[N], w[N];
int n, k, tot, ans, res, all, pos;
bool cmp(int i, int j) {
    return d[i] < d[j];
}
void zhongxin(int S, int u) {
    vis[u] = 1;
    s[u] = 1;
    int maxn = 0;
    for (int i = Head[u], v; i; i = nxt[i]) {
        v = ver[i];
        if (vis[v] || w[v])continue;
        zhongxin(S, v);
        s[u] += s[v];
        maxn = max(maxn, s[v]);
    }
    maxn = max(maxn, S - s[u]);
    if (maxn < res) {
        res = maxn;
        pos = u;
    }
}
void dfs(int u) {
    vis[u] = 1;
    for (int i = Head[u], v; i; i = nxt[i]) {
        v = ver[i];
        if (vis[v] || w[v])continue;
        ++cnt[fa[a[++all] = v] = fa[u]];
        d[v] = d[u] + c[i];
        dfs(v);
    }
}
void work(int S, int u) {
    memset(vis, 0, sizeof vis);
    res = S;
    zhongxin(S, u);
    memset(d, 0, sizeof d);
    memset(cnt, 0, sizeof cnt);
    memset(vis, 0, sizeof vis);
    w[pos] = 1;
    ++cnt[a[all = 1] = fa[pos] = pos];
    for (int i = Head[pos], v; i; i = nxt[i]) {
        v = ver[i];
        if (vis[v] || w[v])continue;
        ++cnt[a[++all] = fa[v] = v];
        d[v] = c[i];
        dfs(v);
    }
    sort(a + 1, a + all + 1, cmp);
    --cnt[fa[a[1]]];
    int l = 1, r = all;
    while (l < r) {
        while (d[a[l]] + d[a[r]] > k)--cnt[fa[a[r--]]];
        ans += r - l - cnt[fa[a[l]]];
        --cnt[fa[a[++l]]];
    }
    int cur = pos;
    for (int i = Head[cur], v; i; i = nxt[i]) {
        v = ver[i];
        if (w[v])continue;
        work(s[v], v);
    }
}
void add(int u, int v, int w) {
    ver[tot] = v;
    c[tot] = w;
    nxt[tot] = Head[u];
    Head[u] = tot++;
}
void Tree() {
    tot = 1;
    memset(Head, 0, sizeof Head);
    for (int i = 1, x, y, z; i < n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    memset(w, 0, sizeof w);
    ans = 0;
    work(n, 0);
    printf("%d\n", ans);
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while ((scanf("%d%d", &n, &k) == 2) && n && k) {
        Tree();
    }
    return 0;
}