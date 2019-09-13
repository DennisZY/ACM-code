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
typedef long long ll;
const int N = 310;
int h[N];
int Head[N], ver[N], nxt[N], vis[N];
int dp[N][N];
int tot;
int n, m;
void dfs(int u)
{
    dp[u][0] = 0;
    for (int i = Head[u]; i; i = nxt[i]) {
        int v = ver[i];
        dfs(v);
        for (int t = m; t >= 0; t--) {
            for (int j = t; j >= 0; j--) {
                dp[u][t] = max(dp[u][t], dp[u][t - j] + dp[v][j]);
            }
        }
    }
    if (u != 0) {
        for (int t = m; t > 0; t--) {
            dp[u][t] = dp[u][t - 1] + h[u];
        }
    }
}
void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
int main()
{
    tot = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, i);
        h[i] = y;
    }
    memset(dp, 0xcf, sizeof dp);
    dfs(0);
    printf("%d\n", dp[0][m]);
    return 0;
}
