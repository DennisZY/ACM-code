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
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
const double PI = acos(-1.);
// mt19937 myrand(time(0));
unordered_map<ll, int> mp;
int tot;
const int N = 100010;
int l[N], r[N];
void get(ll n)
{
    if (n == 1ll) {
        l[++tot] = -1, r[tot] = -1;
        mp[n] = tot;
        return;
    }
    if (mp.count(n))
        return;
    ll mid = n >> 1;
    get(n - mid);
    get(mid);
    ++tot;
    l[tot] = mp[n - mid], r[tot] = mp[mid];
    mp[n] = tot;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        mp.clear();
        tot = -1;
        get(n);
        printf("%d\n", tot + 1);
        for (int i = 0; i <= tot; i++) {
            printf("%d %d\n", l[i], r[i]);
        }
        printf("%d\n", tot);
    }
    return 0;
}