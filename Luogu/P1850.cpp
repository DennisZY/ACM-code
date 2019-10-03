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
int n, m, v, e;
int c[2010], d[2010];
double k[2010], dp[2010][2010][2];
int mp[310][310];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d%d%d", &n, &m, &v, &e);
    for (int i = 1; i <= n; i++)
        scanf("%d", &c[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &d[i]);
    for (int i = 1; i <= n; i++)
        scanf("%lf", &k[i]);
    memset(mp, 0x3f, sizeof mp);
    for (int i = 1; i <= v; i++) {
        mp[i][i] = 0;
    }
    int x, y, z;
    while (e--) {
        scanf("%d%d%d", &x, &y, &z);
        mp[x][y] = mp[y][x] = min(mp[x][y], z);
    }
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j][0] = dp[i][j][1] = 1e14;
        }
    }
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        dp[i][0][0] = dp[i - 1][0][0] + mp[c[i - 1]][c[i]];
        for (int j = 1; j <= min(i, m); j++) {
            dp[i][j][0] = min(dp[i - 1][j][0] + mp[c[i - 1]][c[i]],
                              dp[i - 1][j][1] + k[i - 1] * mp[d[i - 1]][c[i]] +
                                  (1 - k[i - 1]) * mp[c[i - 1]][c[i]]);
            dp[i][j][1] = min(dp[i - 1][j - 1][0] + k[i] * mp[c[i - 1]][d[i]] +
                                  (1 - k[i]) * mp[c[i - 1]][c[i]],
                              dp[i - 1][j - 1][1] + k[i - 1] * k[i] * mp[d[i - 1]][d[i]] +
                                  (1 - k[i - 1]) * k[i] * mp[c[i - 1]][d[i]] +
                                  (1 - k[i - 1]) * (1 - k[i]) * mp[c[i - 1]][c[i]] +
                                  k[i - 1] * (1 - k[i]) * mp[d[i - 1]][c[i]]);
        }
    }
    double ans = min(dp[n][0][0], dp[n][0][1]);
    for (int i = 1; i <= m; i++) {
        ans = min(ans, min(dp[n][i][0], dp[n][i][1]));
    }
    printf("%.2lf\n", ans);
    return 0;
}