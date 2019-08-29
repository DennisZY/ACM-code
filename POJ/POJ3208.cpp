#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
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
int n, m, t;
ll dp[25][4];
void pre() {
    dp[0][0] = 1;
    for (int i = 1; i <= 20; i++) {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) * 9;
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][1];
        dp[i][3] = dp[i - 1][3] * 10 + dp[i - 1][2];
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    pre();
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        m = 3;
        while (dp[m][3] < n)m++;
        for (int i = m, k = 0; i; --i) {
            for (int j = 0; j <= 9; j++) {
                ll cnt = dp[i - 1][3];
                if (j == 6 || k == 3) {
                    for (int l = max(3 - k - (j == 6), 0); l < 3; l++) {
                        cnt += dp[i - 1][l];
                    }
                }
                if (cnt < n) {
                    n -= cnt;
                } else {
                    if (k < 3) {
                        if (j == 6)k++;
                        else k = 0;
                    }
                    printf("%d", j);
                    break;
                }
            }
        }
        puts("");
    }
    return 0;
}