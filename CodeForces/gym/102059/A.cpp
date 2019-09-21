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

const int N = 200010;
int Head[N], nxt[N << 1], ver[N << 1], tot;
int fa[N], sz[N], son[N], top[N], id[N], rk[N], cnt;
int col[N], has[N];
stack<pair<int, int>> st[N];
void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
int n, c, q;
void dfs1(int f, int u)
{
    fa[u] = f;
    son[u] = 0;
    sz[u] = 1;
    for (int i = Head[u], v; i; i = nxt[i]) {
        v = ver[i];
        if (v == f)
            continue;
        dfs1(u, v);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) {
            son[u] = v;
        }
    }
}
void dfs2(int f, int u)
{
    top[u] = f;
    id[u] = ++cnt;
    rk[cnt] = u;
    if (!son[u])
        return;
    dfs2(f, son[u]);
    for (int i = Head[u], v; i; i = nxt[i]) {
        v = ver[i];
        if (v == fa[u] || v == son[u])
            continue;
        dfs2(v, v);
    }
}
void colorchange(int c, int val)
{
    --has[col[c]];
    col[c] += val;
    ++has[col[c]];
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d%d", &n, &c, &q);
    tot = 0;
    for (int i = 1, x, y; i < n; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    dfs1(-1, 1);
    cnt = 0;
    dfs2(1, 1);
    has[0] = c;
    while (q--) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        while (x != -1) {
            int tt = top[x];
            int pre = id[tt] - 1;
            while (st[tt].size() && st[tt].top().first <= id[x]) {
                pair<int, int> tmp = st[tt].top();
                st[tt].pop();
                colorchange(tmp.second, -(tmp.first - pre));
                pre = tmp.first;
            }
            if (st[tt].size()) {
                pair<int, int> tmp = st[tt].top();
                colorchange(tmp.second, -(id[x] - pre));
            }
            colorchange(y, id[x] - id[tt] + 1);
            st[tt].push(make_pair(id[x], y));
            x = fa[tt];
        }
        printf("%d\n", has[z] - (col[y] == z) + (col[y] == z + 1));
    }
    return 0;
}