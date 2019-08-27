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
const ll mod = 1000000007;
const int N = 200010;
ll fac[N], ifc[N];
ll qpow(ll a, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1)(ans *= a) %= mod;
        n >>= 1;
        (a *= a) %= mod;
    }
    return ans;
}
ll C(int n, int m) {
    if (m > n)return 0;
    return fac[n] * ifc[m] % mod * ifc[n - m] % mod;
}
int h, w, n;
ll dp[N];
pair<int, int>a[2010];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    fac[0] = ifc[0] = 1;
    for (int i = 1; i <= 200000; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    ifc[200000] = qpow(fac[200000], mod - 2);
    for (int i = 200000; i > 1; i--) {
        ifc[i - 1] = (ifc[i] * i) % mod;
    }
    scanf("%d%d%d", &h, &w, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    sort(a + 1, a + n + 1);
    a[++n].first = h;
    a[n].second = w;
    for (int i = 1; i <= n; i++) {
        dp[i] = C(a[i].first + a[i].second - 2, a[i].first - 1);
        for (int j = 1; j < i; j++) {
            if (a[j].first > a[i].first || a[j].second > a[i].second)continue;
            dp[i] = (dp[i] - dp[j] * C(a[i].first - a[j].first + a[i].second - a[j].second, a[i].first - a[j].first) % mod + mod) % mod;
        }
    }
    printf("%lld\n", dp[n]);
    return 0;
}