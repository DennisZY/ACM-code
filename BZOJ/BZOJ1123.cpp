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
int n, m;
const int N = 100010;
const int M = 500010;
int Head[N], nxt[M << 1], ver[M << 1], tot;
void add(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
int dfn[N], low[N], sz[N];
bool cut[N];
typedef long long ll;
ll ans[N];
int num;
void tarjan(int u) {
    dfn[u] = low[u] = ++num;
    sz[u] = 1;
    int flag = 0, sum = 0;
    for (int i = Head[u], v; i; i = nxt[i]) {
        v = ver[i];
        if (!dfn[v]) {
            tarjan(v);
            sz[u] += sz[v];
            low[u] = min(low[v], low[u]);
            if (low[v] >= dfn[u]) {
                flag++;
                ans[u] += 1ll * sz[v] * (n - sz[v]);
                sum += sz[v];
                if (u != 1 || flag > 1)cut[u] = true;
            }
        } else {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (cut[u]) {
        ans[u] += 1ll * (n - sum - 1) * (sum + 1) + (n - 1);
    } else {
        ans[u] = 2 * (n - 1);
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    num = 0;
    tarjan(1);
    for (int i = 1; i <= n; i++) {
        printf("%lld\n", ans[i]);
    }
    return 0;
}