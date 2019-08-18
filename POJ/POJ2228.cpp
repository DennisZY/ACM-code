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
const int N = 3840;
int dp[2][N][2];
int u[N];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)scanf("%d", &u[i]);
    int ans = 0;
    memset(dp, 0xcf, sizeof dp);
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i - 1 >= j)dp[i & 1][j][0] = max(dp[(i - 1) & 1][j][0], dp[(i - 1) & 1][j][1]);
            if (j - 1 >= 0)dp[i & 1][j][1] = max(dp[(i - 1) & 1][j - 1][0], dp[(i - 1) & 1][j - 1][1] + u[i]);
        }
    }
    ans = max(dp[n & 1][m][1], dp[n & 1][m][0]);
    memset(dp, 0xcf, sizeof dp);
    dp[1][1][1] = u[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i - 1 >= j)dp[i & 1][j][0] = max(dp[(i - 1) & 1][j][0], dp[(i - 1) & 1][j][1]);
            if (j - 1 >= 0)dp[i & 1][j][1] = max(dp[(i - 1) & 1][j - 1][0], dp[(i - 1) & 1][j - 1][1] + u[i]);
        }
    }
    ans = max(ans, dp[n & 1][m][1]);
    printf("%d\n", ans);
    return 0;
}