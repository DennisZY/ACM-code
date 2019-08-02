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
const int N = 40004;
const int T = 806;
int a[N], b[N], tot;
int c[T][T], f[N];
int L[T], R[T], pos[N];
vector<int>v[N];
int query(int l, int r, int num) {
    return upper_bound(v[num].begin(), v[num].end(), r) - lower_bound(v[num].begin(), v[num].end(), l);
}
void work(int x, int l, int r, int &cnt, int &ans) {
    int tmp = query(l, r, x);
    if (tmp > cnt || (tmp == cnt && x < ans)) {
        ans = x;
        cnt = tmp;
    }
}
int ask(int l, int r) {
    int p = pos[l], q = pos[r];
    int ans = 0, cnt = 0;
    if (p == q) {
        for (int i = l; i <= r; i++)work(a[i], l, r, cnt, ans);
        return b[ans];
    }
    int x = 0, y = 0;
    if (p + 1 <= q - 1) {
        x = p + 1;
        y = q - 1;
    }
    for (int i = l; i <= R[p]; i++)work(a[i], l, r, cnt, ans);
    for (int i = L[q]; i <= r; i++)work(a[i], l, r, cnt, ans);
    if (c[x][y]) work(c[x][y], l, r, cnt, ans);
    return b[ans];
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
    copy(a + 1, a + n + 1, b + 1);
    sort(b + 1, b + n + 1);
    tot = unique(b + 1, b + n + 1) - (b + 1);
    for (int i = 1; i <= n; i++) {
        a[i] = lower_bound(b + 1, b + tot + 1, a[i]) - b;
        v[a[i]].push_back(i);
    }
    int t = sqrt(log(n) / log(2) * n);
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
    for (int i = 1; i <= t; i++) {
        for (int i = 1; i <= tot; i++)f[i] = 0;
        int cnt = 0, ans = 0;
        for (int j = L[i]; j <= n; j++) {
            if (++f[a[j]] > cnt || (f[a[j]] == cnt && a[j] < ans)) {
                cnt = f[a[j]];
                ans = a[j];
            }
            c[i][pos[j]] = ans;
        }
    }
    int x = 0;
    while (m--) {
        int l, r;
        scanf("%d%d", &l, &r);
        l = (l + x - 1) % n + 1;
        r = (r + x - 1) % n + 1;
        if (l > r)swap(l, r);
        x = ask(l, r);
        printf("%d\n", x);
    }
    return 0;
}