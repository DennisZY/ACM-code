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
int n, m;
const int N = 550;
int a[N], b[N];
int dp[N], g[N];
void print(int x, int now)
{
    if (x) {
        print(g[x], 0);
        printf("%d", b[x]);
        if (!now)
            putchar(' ');
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    b[0] = -0x3f3f3f3f;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &b[i]);
    fill(dp, dp + m + 1, 0);
    for (int i = 1; i <= n; i++) {
        int val = 0, cnt = 0;
        for (int j = 1; j <= m; j++) {
            if (a[i] == b[j]) {
                dp[j] = val + 1;
                g[j] = cnt;
            }
            if (b[j] < a[i]) {
                if (val < dp[j]) {
                    val = dp[j];
                    cnt = j;
                }
            }
        }
    }
    int ans = 0, id = 0;
    for (int i = 1; i <= m; i++) {
        if (ans < dp[i]) {
            ans = dp[i];
            id = i;
        }
    }
    printf("%d\n", ans);
    print(id, 1);
    puts("");
    return 0;
}