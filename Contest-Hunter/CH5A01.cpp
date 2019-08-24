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
const int N = 5010;
ll dp[N], t[N], f[N];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
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
            dp[i] = min(dp[i], dp[j] + t[i] * (f[i] - f[j]) + s * (f[n] - f[j]));
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}