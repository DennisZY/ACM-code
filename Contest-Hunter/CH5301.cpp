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
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
int dp[310][310];
int s[310], a[310];
int main()
{
    int n;
    scanf("%d", &n);
    memset(dp, 0x3f, sizeof dp);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i];
        dp[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
            }
            dp[l][r] += s[r] - s[l - 1];
        }
    }
    printf("%d\n", dp[1][n]);
    return 0;
}
