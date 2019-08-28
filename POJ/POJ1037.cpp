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
typedef long long ll;
int t, n;
ll m, dp[21][21][2];
void pre() {
    dp[1][1][0] = dp[1][1][1] = 1;
    for (int i = 2; i <= 20; i++) {
        for (int j = 1; j <= i; j++) {
            for (int p = 1; p < j; p++) {
                dp[i][j][1] += dp[i - 1][p][0];
            }
            for (int p = j; p < i; p++) {
                dp[i][j][0] += dp[i - 1][p][1];
            }
        }
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    pre();
    scanf("%d", &t);
    while (t--) {
        scanf("%d%lld", &n, &m);
        int last = 0, k = 0;
        for (int i = 1; i <= n; i++) {
            if (dp[n][i][1] >= m) {
                last = i, k = 1;
                break;
            } else m -= dp[n][i][1];
            if (dp[n][i][0] >= m) {
                last = i, k = 0;
                break;
            } else m -= dp[n][i][0];
        }
        bool used[21];
        memset(used, false, sizeof used);
        printf("%d", last);
        used[last] = true;
        for (int i = 2; i <= n; i++) {
            k ^= 1;
            int j = 0;
            for (int len = 1; len <= n; len++) {
                if (used[len])continue;
                j++;
                if ((k == 1 && len > last) || (k == 0 && len < last)) {
                    if (dp[n - i + 1][j][k] >= m) {
                        last = len;
                        break;
                    } else m -= dp[n - i + 1][j][k];
                }
            }
            used[last] = true;
            printf(" %d", last);
        }
        puts("");
    }
    return 0;
}