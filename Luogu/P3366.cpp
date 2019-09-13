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
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
const int N = 200010;
typedef pair<int, int> PII;
int d[N];
bool vis[N];
int Head[5010], ver[N << 1], nxt[N << 1], c[N << 1];
int tot;
void add(int x, int y, int z)
{
    ver[++tot] = y;
    c[tot] = z;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
int n, m;
void prim()
{
    priority_queue<PII, vector<PII>, greater<PII>> q;
    fill(d, d + n + 1, 0x3f3f3f3f);
    fill(vis, vis + n + 1, false);
    d[1] = 0;
    q.push(PII(0, 1));
    while (q.size()) {
        PII tmp = q.top();
        q.pop();
        int u = tmp.second;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = Head[u], v; i; i = nxt[i]) {
            v = ver[i];
            if (vis[v])
                continue;
            if (d[v] > c[i]) {
                d[v] = c[i];
                q.push(PII(c[i], v));
            }
        }
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    tot = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }
    prim();
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += d[i];
    }
    printf("%d\n", ans);
    return 0;
}