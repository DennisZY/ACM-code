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
int g[31], c[31], s[31], ans[31];
int dp[31][5001], pre[31][5001][2];
int n, m;
void print(int n, int m) {
    if (n == 0) return;
    print(pre[n][m][0], pre[n][m][1]);
    if (pre[n][m][0] == n) {
        for (int i = 1; i <= n; i++) ans[c[i]]++;
    } else {
        for (int i = pre[n][m][0] + 1; i <= n; i++) ans[c[i]] = 1;
    }
}
bool cmp(const int &x, const int &y) {
    return g[x] > g[y];
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(dp, 0x3f, sizeof dp);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &g[i]);
        c[i] = i;
    }
    sort(c + 1, c + n + 1, cmp);
    s[0] = dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + g[c[i]];
        for (int j = i; j <= m; j++) {
            dp[i][j] = dp[i][j - i];
            pre[i][j][0] = i;
            pre[i][j][1] = j - i;
            for (int k = 0; k < i; k++) {
                if (dp[i][j] > dp[k][j - (i - k)] + k * (s[i] - s[k])) {
                    dp[i][j] = dp[k][j - (i - k)] + k * (s[i] - s[k]);
                    pre[i][j][0] = k;
                    pre[i][j][1] = j - (i - k);
                }
            }
        }
    }
    printf("%d\n", dp[n][m]);
    print(n, m);
    for (int i = 1; i <= n; i++)printf("%d%c", ans[i], i == n ? '\n' : ' ');
    return 0;
}