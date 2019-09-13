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
const ll mod = 1000000000;
ll dp[310][310];
char s[310];
ll solve(int l, int r)
{
    if (l > r)
        return 0;
    if (l == r)
        return 1;
    if (s[l] != s[r])
        return 0;
    if (dp[l][r] != -1)
        return dp[l][r];
    dp[l][r] = 0;
    for (int k = l + 2; k <= r; k++) {
        if (s[l + 1] == s[k - 1]) {
            dp[l][r] =
                (dp[l][r] + solve(l + 1, k - 1) * solve(k, r) % mod) % mod;
        }
    }
    return dp[l][r];
}
int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%s", s + 1);
    printf("%lld\n", solve(1, strlen(s + 1)));
    return 0;
}
