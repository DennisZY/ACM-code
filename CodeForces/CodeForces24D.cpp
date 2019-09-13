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
int n, m, x, y;
const int N = 1010;
double d[N][N], dp[N][N];
void work()
{
    for (int i = 1; i <= m; i++) {
        double w = 1.0 / d[i][i];
        d[i][i] = 1;
        d[i][m + 1] *= w;
        if (i == m)
            break;
        d[i][i + 1] *= w;
        w = d[i + 1][i] / d[i][i];
        d[i + 1][i] -= w * d[i][i];
        d[i + 1][i + 1] -= w * d[i][i + 1];
        d[i + 1][m + 1] -= w * d[i][m + 1];
    }
    for (int i = m - 1; i; i--)
        d[i][m + 1] -= d[i + 1][m + 1] * d[i][i + 1];
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = n - 1; i >= x; i--) {
        d[1][1] = d[m][m] = -2 / 3.0;
        d[1][2] = d[m][m - 1] = 1 / 3.0;
        for (int j = 2; j < m; j++) {
            d[j][m + 1] = -dp[i + 1][j] / 4.0 - 1;
            d[j][j] = -3 / 4.0;
            d[j][j - 1] = d[j][j + 1] = 1 / 4.0;
        }
        if (m == 1)
            d[1][1] = -1 / 2.0;
        d[1][m + 1] = -dp[i + 1][1] / 3.0 - 1;
        d[m][m + 1] = -dp[i + 1][m] / 3.0 - 1;
        if (m == 1)
            d[m][m + 1] = -dp[i + 1][m] / 2.0 - 1;
        work();
        for (int j = 1; j <= m; j++)
            dp[i][j] = d[j][m + 1];
    }
    printf("%.5lf\n", dp[x][y]);
    return 0;
}