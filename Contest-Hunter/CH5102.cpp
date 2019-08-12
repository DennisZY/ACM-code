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

const int N = 210;
int mmp[N][N];
int dp[1010][N][N];
int q[1010];
int l, n;
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d", &l, &n);
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            scanf("%d", &mmp[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)scanf("%d", &q[i]);
    memset(dp, 0x3f, sizeof dp);
    q[0] = 3;
    dp[0][1][2] = 0;
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= l; j++) {
                if (dp[k - 1][i][j] != 0x3f3f3f3f) {
                    if (q[k] != i && q[k] != j)dp[k][i][j] = min(dp[k][i][j], dp[k - 1][i][j] + mmp[q[k - 1]][q[k]]);
                    if (q[k - 1] != q[k] && q[k] != j)dp[k][q[k - 1]][j] = min(dp[k][q[k - 1]][j], dp[k - 1][i][j] + mmp[i][q[k]]);
                    if (q[k - 1] != q[k] && q[k] != i)dp[k][i][q[k - 1]] = min(dp[k][i][q[k - 1]], dp[k - 1][i][j] + mmp[j][q[k]]);
                }
            }
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= l; i++) {
        for (int j = 1; j <= l; j++) {
            ans = min(ans, dp[n][i][j]);
        }
    }
    printf("%d\n", ans);
    return 0;
}