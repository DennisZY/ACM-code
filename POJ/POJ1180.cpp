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
const int N = 300010;
int n, s;
int t[N], c[N], dp[N], q[N];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &s);
    t[0] = c[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &t[i], &c[i]);
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    int l = 1, r = 1;
    q[1] = 0;
    for (int i = 1; i <= n; i++) {
        while (l < r && (dp[q[l + 1]] - dp[q[l]]) <= (s + t[i]) * (c[q[l + 1]] - c[q[l]]))l++;
        dp[i] = dp[q[l]] - (s + t[i]) * c[q[l]] + t[i] * c[i] + s * c[n];
        while (l < r && (dp[q[r]] - dp[q[r - 1]]) * (c[i] - c[q[r]]) >= (dp[i] - dp[q[r]]) * (c[q[r]] - c[q[r - 1]]))r--;
        q[++r] = i;
    }
    printf("%d\n", dp[n]);
    return 0;
}