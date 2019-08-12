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
const int N = 2010;
ll dp[N][N];
ll a[N], b[N];
int n, m;
int query(ll x) {
    return lower_bound(b + 1, b + m + 1, x) - b;
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    m = unique(b + 1, b + n + 1) - (b + 1);
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        ll val = dp[i - 1][0];
        for (int j = 1; j <= m; j++) {
            val = min(val, dp[i - 1][j]);
            dp[i][j] = min(dp[i][j], val + abs(a[i] - b[j]));
        }
    }
    ll ans = 0x3f3f3f3f;
    for (int i = 1; i <= m; i++) {
        ans = min(ans, dp[n][i]);
    }
    printf("%lld\n", ans);
    return 0;
}