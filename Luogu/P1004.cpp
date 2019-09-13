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
int mmp[20][20], dp[20][20];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n, x, y, z;
    scanf("%d", &n);
    while (scanf("%d%d%d", &x, &y, &z), x || y || z) {
        mmp[x][y] = z;
    }
    int y1, y2;
    for (int l = 2; l <= n * 2; l++) {
        for (int x1 = l - 1; x1 >= 1; x1--) {
            for (int x2 = l - 1; x2 >= 1; x2--) {
                y1 = l - x1;
                y2 = l - x2;
                dp[x1][x2] = max(max(dp[x1][x2], dp[x1 - 1][x2 - 1]),
                                 max(dp[x1][x2 - 1], dp[x1 - 1][x2])) +
                             mmp[x1][y1];
                if (x1 != x2)
                    dp[x1][x2] += mmp[x2][y2];
            }
        }
    }
    printf("%d\n", dp[n][n]);
    return 0;
}