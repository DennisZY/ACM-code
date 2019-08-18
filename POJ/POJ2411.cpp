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
ll dp[20][1 << 11];
bool check[1 << 11];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    while (scanf("%d%d", &n, &m) && n) {
        int res = 1 << m;
        for (int i = 1; i < res; i++) {
            bool is = false, cnt = false;
            for (int j = 0; j < m; j++) {
                if (i >> j & 1)is |= cnt, cnt = false;
                else cnt ^= true;
            }
            check[i] = is | cnt ? false : true;
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < res; j++) {
                dp[i][j] = 0;
                for (int k = 0; k < res; k++) {
                    if ((j & k) == 0 && check[j | k]) {
                        dp[i][j] += dp[i - 1][k];
                    }
                }
            }
        }
        printf("%lld\n", dp[n][0]);
    }
    return 0;
}