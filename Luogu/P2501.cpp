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

const int MOD = 9999973;
const int N = 128;
inline void udpate(int &a, int b)
{
    a += b;
    if (a >= MOD)
        a -= MOD;
}
int C(int x) { return x * (x - 1) / 2 % MOD; }
int dp[N][N][N];
int n, m;

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k <= m - j; k++) {
                udpate(dp[i][j][k], dp[i - 1][j][k]);
                if (j >= 1)
                    udpate(dp[i][j][k],
                           dp[i - 1][j - 1][k] * (m - k - (j - 1)) % MOD);
                if (k >= 1)
                    udpate(dp[i][j][k],
                           dp[i - 1][j + 1][k - 1] * (j + 1) % MOD);
                if (j >= 2)
                    udpate(dp[i][j][k], 1ll * dp[i - 1][j - 2][k] *
                                            C(m - k - (j - 2)) % MOD);
                if (k >= 2)
                    udpate(dp[i][j][k],
                           1ll * dp[i - 1][j + 2][k - 2] * C(j + 2) % MOD);
                if (k >= 1)
                    udpate(dp[i][j][k], 1ll * dp[i - 1][j][k - 1] * (j) *
                                            (m - j - (k - 1)) % MOD);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= m - i; j++) {
            udpate(ans, dp[n][i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}