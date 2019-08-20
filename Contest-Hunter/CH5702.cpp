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
char s1[110], s2[110];
int n1, n2, len1, len2;
ll dp[110][33];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    while (~scanf("%s%d%s%d", s2, &n2, s1, &n1)) {
        ll fin;
        len1 = strlen(s1), len2 = strlen(s2);
        for (int i = 0; i < len1; i++) {
            int pos = i;
            dp[i][0] = 0;
            for (int j = 0; j < len2; j++) {
                int cnt = 0;
                while (s1[pos] != s2[j]) {
                    pos++;
                    if (pos == len1)pos = 0;
                    if (++cnt >= len1) {
                        printf("0\n");
                        goto here;
                    }
                }
                pos++;
                if (pos == len1)pos = 0;
                dp[i][0] += cnt + 1;
            }
        }
        for (int j = 1; j <= 30; j++) {
            for (int i = 0; i < len1; i++) {
                dp[i][j] = dp[i][j - 1] + dp[(i + dp[i][j - 1]) % len1][j - 1];
            }
        }
        fin = 0;
        for (int i = 0; i < len1; i++) {
            ll x = i, ans = 0;
            for (int k = 30; k >= 0; k--) {
                if (x + dp[x % len1][k] <= len1 * n1) {
                    x += dp[x % len1][k];
                    ans += 1 << k;
                }
            }
            if (ans > fin) {
                fin = ans;
            }
        }
        printf("%lld\n", fin / n2);
here:
        ;
    }
    return 0;
}