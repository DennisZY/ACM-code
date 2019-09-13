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
const int N = 300010;
int n, s;
ll t[N], c[N], dp[N], q[N];
int l, r;
int query(int i, int k)
{
    if (l == r)
        return q[l];
    int L = l, R = r;
    while (L < R) {
        int mid = (L + R) >> 1;
        if (dp[q[mid + 1]] - dp[q[mid]] <= k * (c[q[mid + 1]] - c[q[mid]])) {
            L = mid + 1;
        } else {
            R = mid;
        }
    }
    return q[L];
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &s);
    t[0] = c[0] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &t[i], &c[i]);
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }
    dp[0] = 0;
    l = 1, r = 1;
    q[1] = 0;
    for (int i = 1; i <= n; i++) {
        int ans = query(i, s + t[i]);
        dp[i] = dp[ans] - (s + t[i]) * c[ans] + t[i] * c[i] + s * c[n];
        while (l < r && (dp[q[r]] - dp[q[r - 1]]) * (c[i] - c[q[r]]) >=
                            (dp[i] - dp[q[r]]) * (c[q[r]] - c[q[r - 1]]))
            r--;
        q[++r] = i;
    }
    printf("%lld\n", dp[n]);
    return 0;
}