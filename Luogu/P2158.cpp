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
const int N = 40010;
int pr, prime[N], v[N], mu[N];
int pre[N];
void primejudge(int lim) {
    memset(v, 0, sizeof v);
    pr = 0;
    mu[1] = 1;
    for (int i = 2; i <= lim; ++i) {
        if (!v[i]) {
            prime[pr++] = i;
            v[i] = i;
            mu[i] = -1;
        }
        for (int j = 0; j < pr && lim / i >= prime[j]; j++) {
            v[i * prime[j]] = prime[j];
            if (v[i] <= prime[j])break;
            mu[i * prime[j]] = -mu[i];
        }
    }
}
int main() {
    primejudge(40000);
    int n;
    scanf("%d", &n);
    n--;
    if (n == 0) {
        puts("0");
        return 0;
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += 1ll * mu[i] * (n / i) * (n / i);
    }
    printf("%lld\n", ans + 2);
    return 0;
}
