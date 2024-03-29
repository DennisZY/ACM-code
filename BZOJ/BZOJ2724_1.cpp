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
const int N = 40004;
const int T = 40;
int a[N], b[N], tot;
int c[T][T][N], f[T][T][2], now[2];
int L[T], R[T], pos[N];
void work(int x, int y, int num)
{
    ++c[x][y][num];
    if (c[x][y][num] > now[0] || (c[x][y][num] == now[0] && num < now[1])) {
        now[0] = c[x][y][num];
        now[1] = num;
    }
}
int ask(int l, int r)
{
    int p = pos[l], q = pos[r];
    int x = 0, y = 0;
    if (p + 1 <= q - 1) {
        x = p + 1;
        y = q - 1;
    }
    memcpy(now, f[x][y], sizeof(now));
    if (p == q) {
        for (int i = l; i <= r; i++)
            work(x, y, a[i]);
        for (int i = l; i <= r; i++)
            --c[x][y][a[i]];
    } else {
        for (int i = l; i <= R[p]; i++)
            work(x, y, a[i]);
        for (int i = L[q]; i <= r; i++)
            work(x, y, a[i]);
        for (int i = l; i <= R[p]; i++)
            --c[x][y][a[i]];
        for (int i = L[q]; i <= r; i++)
            --c[x][y][a[i]];
    }
    return b[now[1]];
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    copy(a + 1, a + n + 1, b + 1);
    sort(b + 1, b + n + 1);
    tot = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; i++)
        a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
    int t = cbrt(n);
    int len = t ? n / t : n;
    for (int i = 1; i <= t; i++) {
        L[i] = (i - 1) * len + 1;
        R[i] = i * len;
    }
    if (R[t] < n) {
        L[t + 1] = R[t] + 1;
        R[++t] = n;
    }
    for (int i = 1; i <= t; i++) {
        for (int j = L[i]; j <= R[i]; j++) {
            pos[j] = i;
        }
    }
    memset(c, 0, sizeof c);
    memset(f, 0, sizeof f);
    for (int i = 1; i <= t; i++) {
        for (int j = i; j <= t; j++) {
            for (int k = L[i]; k <= R[j]; k++) {
                ++c[i][j][a[k]];
            }
            for (int k = 1; k <= tot; k++) {
                if (c[i][j][k] > f[i][j][0]) {
                    f[i][j][0] = c[i][j][k];
                    f[i][j][1] = k;
                }
            }
        }
    }
    int x = 0;
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        l = (l + x - 1) % n + 1;
        r = (r + x - 1) % n + 1;
        if (l > r)
            swap(l, r);
        x = ask(l, r);
        printf("%d\n", x);
    }
    return 0;
}