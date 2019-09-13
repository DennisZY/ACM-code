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
const int N = 6000;
int h[N];
int Head[N], ver[N], nxt[N], vis[N];
int dp[N][2];
int tot;
void add(int x, int y)
{
    ver[++tot] = y;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
void dfs(int u)
{
    dp[u][0] = 0;
    dp[u][1] = h[u];
    for (int i = Head[u]; i; i = nxt[i]) {
        int v = ver[i];
        dfs(v);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
}
int main()
{
    tot = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &h[i]);
    int x, y;
    for (int i = 1; i < n; i++) {
        scanf("%d%d", &x, &y);
        add(y, x);
        vis[x] = 1;
    }
    int root;
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            root = i;
            break;
        }
    }
    dfs(root);
    printf("%d\n", max(dp[root][0], dp[root][1]));
    return 0;
}
