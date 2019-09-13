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
typedef long long ll;
const int N = 100010;
int n, m, p, l, r;
ll d[N], h[N], t[N], a[N], s[N], dp[110][N], res[N], q[N], sa[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 2; i <= n; i++)
        scanf("%lld", &d[i]);
    s[1] = 0;
    for (int i = 2; i <= n; i++) {
        s[i] = s[i - 1] + d[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%lld%lld", &h[i], &t[i]);
    }
    for (int i = 1; i <= m; i++) {
        a[i] = t[i] - s[h[i]];
    }
    sort(a + 1, a + m + 1);
    sa[0] = 0;
    for (int i = 1; i <= m; i++) {
        sa[i] = sa[i - 1] + a[i];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= p; i++) {
        for (int j = 1; j <= m; j++)
            res[j] = dp[i - 1][j] + sa[j];
        q[l = r = 1] = 0;
        for (int j = 1; j <= m; j++) {
            while (l < r &&
                   res[q[l + 1]] - res[q[l]] <= a[j] * (q[l + 1] - q[l]))
                l++;
            dp[i][j] = min(dp[i - 1][j], res[q[l]] + a[j] * (j - q[l]) - sa[j]);
            if (res[j] >= 0x3f3f3f3f3f3f3f3fll)
                continue;
            while (l < r && (res[q[r]] - res[q[r - 1]]) * (j - q[r]) >=
                                (res[j] - res[q[r]]) * (q[r] - q[r - 1]))
                r--;
            q[++r] = j;
        }
    }
    printf("%lld\n", dp[p][m]);
    return 0;
}