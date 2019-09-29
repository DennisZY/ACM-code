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
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
const double PI = acos(-1.);
// mt19937 myrand(time(0));
const int N = 1010;
int cnt, stat[N];
ll dp[10][N][100];
int num[N];
int get(int x)
{
    int res = 0;
    while (x) {
        res++;
        x -= x & (-x);
    }
    return num[cnt] = res;
}
int n, m;
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    int res = (1 << n) - 1;
    cnt = 0;
    for (int i = 0; i <= res; i++) {
        if (!(i & (i << 1))) {
            stat[++cnt] = i;
            dp[1][cnt][get(i)] = 1;
        }
    }
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= cnt; j++) {
            int x = stat[j];
            for (int k = 1; k <= cnt; k++) {
                int y = stat[k];
                if (x & y)
                    continue;
                if ((x << 1) & y)
                    continue;
                if (x & (y << 1))
                    continue;
                for (int l = 0; l <= m - num[j]; l++) {
                    dp[i][j][l + num[j]] += dp[i - 1][k][l];
                }
            }
        }
    }
    ll ans = 0;
    for (int i = 1; i <= cnt; i++) {
        ans += dp[n][i][m];
    }
    printf("%lld\n", ans);
    return 0;
}