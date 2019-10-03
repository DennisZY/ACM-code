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
const ll mod = 100000000;
ll dp[13][1 << 12 | 1];
bool check[13][1 << 12 | 1];
void update(ll &a, ll b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        int tmp = 0;
        for (int j = 1, x; j <= m; j++) {
            scanf("%d", &x);
            (tmp <<= 1) |= x;
        }
        for (int j = 0; j < (1 << m); j++) {
            if (!(j & (j << 1)) && ((j & tmp) == j))
                check[i][j] = true;
        }
    }
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < (1 << m); j++) {
            for (int k = 0; k < (1 << m); k++) {
                if (!(j & k) && check[i][k]) {
                    update(dp[i][k], dp[i - 1][j]);
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < (1 << m); i++) {
        update(ans, dp[n][i]);
    }
    printf("%lld\n", ans);
    return 0;
}