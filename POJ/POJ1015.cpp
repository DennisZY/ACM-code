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
int n, m;
int dp[25][805];
int d[205][25][805];
int a[205], b[205], suma, sumb, t;
int top, num[25];
int kase = 0;
void genlist(int i, int j, int k)
{
    if (j == 0)return ;
    int now = d[i][j][k];
    genlist(now - 1, j - 1, k - (a[now] - b[now]));
    num[++top] = now;
    suma += a[now], sumb += b[now];
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (scanf("%d%d", &n, &m) && n) {
        for (int i = 1; i <= n; i++)scanf("%d%d", &a[i], &b[i]);
        memset(dp, 0xcf, sizeof dp);
        dp[0][400] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= 800; k++)d[i][j][k] = d[i - 1][j][k];
            }
            for (int j = m; j; j--) {
                for (int k = 0; k <= 800; k++) {
                    if (k - (a[i] - b[i]) < 0 || k - (a[i] - b[i]) > 800)continue;
                    if (dp[j][k] < dp[j - 1][k - (a[i] - b[i])] + a[i] + b[i]) {
                        dp[j][k] = dp[j - 1][k - (a[i] - b[i])] + a[i] + b[i];
                        d[i][j][k] = i;
                    }
                }
            }
        }
        int ans = 0;
        for (int k = 0; k <= 400; k++) {
            if (dp[m][400 + k] >= 0 && dp[m][400 + k] >= dp[m][400 - k]) {
                ans = 400 + k;
                break;
            }
            if (dp[m][400 - k] >= 0) {
                ans = 400 - k;
                break;
            }
        }
        top = 0;
        suma = sumb = 0;
        genlist(n, m, ans);
        printf("Jury #%d\n", ++kase);
        printf("Best jury has value %d for prosecution and value %d for defence:\n", suma, sumb);
        for (int i = 1; i <= top; i++)printf(" %d", num[i]);
        printf("\n\n");
    }
    return 0;
}