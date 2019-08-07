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
ll dp[35][35][35][35][35];
int m[10];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    while (scanf("%d", &n) == 1 && n) {
        for (int i = 1; i <= n; i++)scanf("%d", &m[i]);
        while (n < 5) {
            m[++n] = 0;
        }
        memset(dp, 0, sizeof dp);
        dp[0][0][0][0][0] = 1;
        for (int i = 1; i <= m[1]; i++) {
            for (int j = 1; j <= m[2]; j++) {
                for (int k = 1; k <= m[3]; k++) {
                    for (int l = 1; l <= m[4]; l++) {
                        for (int o = j; o <= m[5]; o++) {
                            if (i < m[1])dp[i + 1][j][k][l][o] += dp[i][j][k][l][o];
                            if (j < i && j < m[2])dp[i][j + 1][k][l][o] += dp[i][j][k][l][o];
                            if (k < j && k < m[3])dp[i][j][k + 1][l][o] += dp[i][j][k][l][o];
                            if (l < k && l < m[4])dp[i][j][k][l + 1][o] += dp[i][j][k][l][o];
                            if (o < l && o < m[5])dp[i][j][k][l][o + 1] += dp[i][j][k][l][o];
                        }
                    }
                }
            }
        }
        printf("%lld\n", dp[m[1]][m[2]][m[3]][m[4]][m[5]]);
    }
    return 0;
}