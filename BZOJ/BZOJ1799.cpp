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
int dp[82][10][82][82], ten[82][10];
int num[10];
int calc(int pos, int sum, int mod, int s, bool e)
{
    if (s - sum < 0)
        return 0;
    else if (!e)
        return dp[s][pos + 1][s - sum][(s - mod) % s];
    else if (pos == -1) {
        if (sum == s && mod == 0)
            return 1;
        else
            return 0;
    } else {
        int res = 0;
        for (int d = 0; d <= num[pos]; d++) {
            res += calc(pos - 1, sum + d, (mod + ten[s][pos] * d) % s, s,
                        d == num[pos]);
        }
        return res;
    }
}
int calc(int x)
{
    int len = 0;
    while (x)
        num[len++] = x % 10, x /= 10;
    int res = 0;
    for (int i = 1; i <= 81; i++)
        res += calc(len - 1, 0, 0, i, true);
    return res;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    for (int s = 1; s <= 81; s++) {
        memset(dp[s], 0, sizeof dp[s]);
        dp[s][0][0][0] = 1;
        ten[s][0] = 1 % s;
        for (int i = 1; i <= 9; i++)
            ten[s][i] = (ten[s][i - 1] * 10) % s;
        for (int i = 1; i <= 9; i++) {
            for (int j = 0; j <= i * 9; j++) {
                for (int k = 0; k <= s; k++) {
                    for (int d = 0; d <= 9 && j - d >= 0; d++) {
                        dp[s][i][j][k] +=
                            dp[s][i - 1][j - d]
                              [((k - ten[s][i - 1] * d) % s + s) % s];
                    }
                }
            }
        }
    }
    int l, r;
    while (scanf("%d%d", &l, &r) == 2) {
        printf("%d\n", calc(r) - calc(l - 1));
    }
    return 0;
}