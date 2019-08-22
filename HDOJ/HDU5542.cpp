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
const int mod = 1000000007;
const int N = 1010;
int a[N], b[N], c[N];
int dp[N][N];
int n, m;
void add(int x, int y) {
    y %= mod;
    while (x <= n + 1) {
        c[x] += y;
        if (c[x] >= mod )c[x] -= mod;
        x += x & (-x);
    }
}
int sum(int x) {
    int ans = 0;
    while (x) {
        ans += c[x];
        if (ans >= mod)ans -= mod;
        x -= x & (-x);
    }
    return ans;
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    for (int kase = 1; kase <= t; kase++) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
        }
        sort(b + 1, b + n + 1);
        for (int i = 1; i <= n; i++) {
            a[i] = lower_bound(b + 1, b + n + 1, a[i]) - b + 1;
        }
        a[0] = 1;
        dp[0][0] = 1;
        for (int i = 1; i <= m; i++) {
            memset(c, 0, sizeof c);
            add(1, dp[i - 1][0]);
            for (int j = 1; j <= n; j++) {
                dp[i][j] = sum(a[j] - 1);
                add(a[j], dp[i - 1][j]);
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            ans = (ans + dp[m][i]) % mod;
        }
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}