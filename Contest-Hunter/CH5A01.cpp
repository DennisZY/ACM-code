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
const int N = 5010;
ll dp[N], t[N], f[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n, s;
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &t[i], &f[i]);
        t[i] += t[i - 1];
        f[i] += f[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        dp[i] = 0x3f3f3f3f3f3f3f3f;
        for (int j = 0; j < i; j++) {
            dp[i] =
                min(dp[i], dp[j] + t[i] * (f[i] - f[j]) + s * (f[n] - f[j]));
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}