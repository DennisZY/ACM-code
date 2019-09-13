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

const int N = 3010;
int a[N], b[N], dp[N][N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    b[0] = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    for (int i = 0; i <= n; i++) {
        fill(dp[i], dp[i] + n + 1, 0);
    }
    for (int i = 1; i <= n; i++) {
        int val = 0;
        if (b[0] < a[i - 1])
            val = dp[i - 1][0];
        for (int j = 1; j <= n; j++) {
            if (a[i] == b[j])
                dp[i][j] = val + 1;
            else
                dp[i][j] = dp[i - 1][j];
            if (b[j] < a[i])
                val = max(dp[i - 1][j], val);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i]);
    }
    printf("%d\n", ans);
    return 0;
}