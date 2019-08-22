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
struct res {
    int l, p, s;
    bool operator < (const res &tmp) const {
        return s < tmp.s;
    }
} a[110];
int n, m, dp[110][16010], q[16010];
int calc(int i, int k) {
    return dp[i - 1][k] - a[i].p * k;
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout)
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].l, &a[i].p, &a[i].s);
    }
    sort(a + 1, a + m + 1);
    for (int i = 1; i <= m; i++) {
        int l = 1, r = 0;
        for (int k = max(a[i].s - a[i].l, 0); k <= a[i].s - 1; k++) {
            while (l <= r && calc(i, q[r]) <= calc(i, k))r--;
            q[++r] = k;
        }
        for (int j = 1; j <= n; j++) {
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            if (j >= a[i].s) {
                while (l <= r && q[l] < j - a[i].l)l++;
                if (l <= r)dp[i][j] = max(dp[i][j], calc(i, q[l]) + a[i].p * j);
            }
        }
    }
    printf("%d\n", dp[m][n]);
    return 0;
}