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
int n, m;
int dp[110][110][2];
char s[110];
int a[110];
char str[2];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%s%d", str, &a[i]);
        a[i + n] = a[i];
        s[i] = s[i + n] = str[0];
    }
    int res = n << 1;
    for (int i = 1; i <= res; i++) {
        for (int j = 1; j <= res; j++) {
            dp[i][j][0] = -0x3f3f3f3f;
            dp[i][j][1] = 0x3f3f3f3f;
        }
    }
    for (int i = 1; i <= res; i++) {
        dp[i][i][0] = a[i];
        dp[i][i][1] = a[i];
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= res; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                if (s[k + 1] == 'x') {
                    dp[l][r][0] = max(dp[l][r][0], dp[l][k][0] * dp[k + 1][r][0]);
                    dp[l][r][0] = max(dp[l][r][0], dp[l][k][1] * dp[k + 1][r][1]);
                    dp[l][r][1] = min(dp[l][r][1], dp[l][k][0] * dp[k + 1][r][1]);
                    dp[l][r][1] = min(dp[l][r][1], dp[l][k][1] * dp[k + 1][r][0]);
                    dp[l][r][1] = min(dp[l][r][1], dp[l][k][1] * dp[k + 1][r][1]);
                    dp[l][r][1] = min(dp[l][r][1], dp[l][k][0] * dp[k + 1][r][0]);
                } else {
                    dp[l][r][0] = max(dp[l][r][0], dp[l][k][0] + dp[k + 1][r][0]);
                    dp[l][r][1] = min(dp[l][r][1], dp[l][k][1] + dp[k + 1][r][1]);
                }
            }
        }
    }
    int x, y, ans = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++) {
        if (ans < dp[i][i + n - 1][0]) {
            ans = dp[i][i + n - 1][0];
        }
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; i++) {
        if (ans == dp[i][i + n - 1][0]) {
            printf("%d ", i);
        }
    }
    return 0;
}