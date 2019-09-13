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
int dp1[210][210];
int dp2[210][210];
int s[210], a[210];
int main()
{
    int n;
    scanf("%d", &n);
    memset(dp1, 0x3f, sizeof dp1);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    int res = n << 1;
    for (int i = 1; i <= res; i++) {
        s[i] = s[i - 1] + a[i];
        dp1[i][i] = 0;
    }
    for (int len = 2; len <= n; len++) {
        for (int l = 1; l + len - 1 <= res; l++) {
            int r = l + len - 1;
            for (int k = l; k < r; k++) {
                dp1[l][r] = min(dp1[l][r], dp1[l][k] + dp1[k + 1][r]);
                dp2[l][r] = max(dp2[l][r], dp2[l][k] + dp2[k + 1][r]);
            }
            dp1[l][r] += s[r] - s[l - 1];
            dp2[l][r] += s[r] - s[l - 1];
        }
    }
    int minn = 0x3f3f3f3f, maxn = 0;
    for (int i = 1; i <= n; i++) {
        minn = min(minn, dp1[i][i + n - 1]);
        maxn = max(maxn, dp2[i][i + n - 1]);
    }
    printf("%d\n%d\n", minn, maxn);
    return 0;
}
