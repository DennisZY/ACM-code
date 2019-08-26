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
typedef long double ld;
int n, l, p;
char s[37];
ll len[100010];
struct query {
    int x, l, r;
} q[100010];
ld dp[100010];
int get(int i, int L, int R) {
    int ans = 0;
    while (L <= R) {
        int mid = (L + R) >> 1;
        if (q[mid].l <= i && q[mid].r >= i) {
            ans = mid;
            break;
        }
        if (i >= q[mid].l)L = mid + 1;
        else R = mid - 1;
    }
    return q[ans].x;
}
ld calc(int i, int j) {
    ld ans = 1, num = abs((ld)(len[i] - len[j] + i - j - 1 - l));
    for (int i = 1; i <= p; i++)ans *= num;
    return ans + dp[j];
}
void insert(int i, int &L, int &R) {
    int w = -1;
    while (L <= R) {
        if (calc(q[R].l, i) <= calc(q[R].l, q[R].x))w = q[R--].l;
        else {
            if (calc(q[R].r, q[R].x) > calc(q[R].r, i)) {
                int l = q[R].l, r = q[R].r;
                while (l < r) {
                    int mid = (l + r) >> 1;
                    if (calc(mid, i) > calc(mid, q[R].x))l = mid + 1;
                    else r = mid;
                }
                q[R].r = l - 1;
                w = l;
            }
            break;
        }
    }
    if (w != -1) {
        q[++R].l = w;
        q[R].r = n;
        q[R].x = i;
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d", &n, &l, &p);
        len[0] = 0;
        for (int i = 1; i <= n; i++) {
            scanf("%s", s);
            len[i] = strlen(s);
            len[i] += len[i - 1];
        }
        int L = 1, R = 1;
        q[1].x = 0;
        q[1].l = 1;
        q[1].r = n;
        for (int i = 1; i <= n; i++) {
            int j = get(i, L, R);
            dp[i] = calc(i, j);
            while (L <= R && q[L].r <= i)++L;
            q[L].l = i + 1;
            insert(i, L, R);
        }
        if (dp[n] > 1e18)puts("Too hard to arrange");
        else printf("%lld\n", (ll)dp[n]);
        puts("--------------------");
    }
    return 0;
}