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
#include <map>
#include <set>
/*
#include <unordered_map>
#include <unordered_set>
*/
using namespace std;
const int N = 100010;
int Head[N], nxt[N << 1], ver[N << 1], tot;
struct query {
    int x, id;
} q[400010];
int tail[N], qnxt[400010], top;
void add(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
void qadd(int x, int y, int i) {
    q[++top].x = y;
    q[top].id = i;
    qnxt[top] = tail[x];
    tail[x] = top;
}
int fa[N];
int lca[200010];
int get(int x) {
    while (x != fa[x])x = fa[x] = fa[fa[x]];
    return x;
}
int vis[N];
void tarjan(int u) {
    vis[u] = 1;
    for (int i = Head[u], v; i; i = nxt[i]) {
        v = ver[i];
        if (vis[v])continue;
        tarjan(v);
        fa[v] = u;
    }
    for (int i = tail[u], v; i; i = qnxt[i]) {
        v = q[i].x;
        if (vis[v] == 2) {
            lca[q[i].id] = get(v);
        }
    }
    vis[u] = 2;
}
int cnt[3], F[N];
void dfs(int u) {
    vis[u] = 1;
    for (int i = Head[u], v; i; i = nxt[i]) {
        v = ver[i];
        if (vis[v])continue;
        dfs(v);
        F[u] += F[v];
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i < n; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        qadd(x, y, i);
        qadd(y, x, i);
        if (x == y)lca[i] = x;
        F[x]++;
        F[y]++;
    }
    for (int i = 1; i <= n; i++)fa[i] = i;
    tarjan(1);
    for (int i = 1; i <= m; i++) {
        F[lca[i]] -= 2;
    }
    fill(vis, vis + n + 1, 0);
    dfs(1);
    for (int i = 2; i <= n; i++) {
        if (F[i] == 0)cnt[0]++;
        if (F[i] == 1)cnt[1]++;
    }
    printf("%lld\n", 1ll * cnt[0] * m + cnt[1]);
    return 0;
}