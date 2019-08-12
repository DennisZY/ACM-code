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
typedef long long ll;
int mmp[55][55], dp[55][55];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%d", &mmp[i][j]);
        }
    }
    for (int l = 2; l <= n + m; l++) {
        for (int x1 = min(n, l - 1); x1 >= 1; x1--) {
            for (int x2 = min(n, l - 1); x2 >= 1; x2--) {
                int y1 = l - x1, y2 = l - x2;
                dp[x1][x2] = max(max(dp[x1][x2], dp[x1 - 1][x2 - 1]), max(dp[x1][x2 - 1], dp[x1 - 1][x2])) + mmp[x1][y1];
                if (x1 != x2)dp[x1][x2] += mmp[x2][y2];
            }
        }
    }
    printf("%d\n", dp[n][n]);
    return 0;
}