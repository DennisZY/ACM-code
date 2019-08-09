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
const int N = 60010;
const int M = 2500010;
struct sgmt {
    int l, r, sz;
} tr[M];
struct rec {
    int op, x, y, z;
} q[N];
int root[N], zxs[N];
int tot, n, m, p;
int a[N], b[N];
int get(int val) {
    return lower_bound(b + 1, b + p + 1, val) - b;
}
int newnode() {
    ++tot;
    tr[tot].l = tr[tot].r = tr[tot].sz = 0;
    return tot;
}
int build(int l, int r) {
    int rt = newnode();
    if (l != r) {
        int mid = (l + r) >> 1;
        tr[rt].l = build(l, mid);
        tr[rt].r = build(mid + 1, r);
    }
    return rt;
}
int update(int rt, int val, int cnt) {
    int tmp = newnode();
    int nrt = tmp;
    int l = 1, r = p;
    tr[nrt].sz = tr[rt].sz + cnt;
    while (l < r) {
        int mid = (l + r) >> 1;
        // printf("````````````%d %d %d %d\n", mid, l, r, val);
        if (val <= mid) {
            tr[nrt].l = newnode();
            tr[nrt].r = tr[rt].r;
            nrt = tr[nrt].l;
            rt = tr[rt].l;
            r = mid;
        } else {
            tr[nrt].r = newnode();
            tr[nrt].l = tr[rt].l;
            nrt = tr[nrt].r;
            rt = tr[rt].r;
            l = mid + 1;
        }
        tr[nrt].sz = tr[rt].sz + cnt;
    }
    // printf("!!!!!!!!%d  %d\n", val, l);
    return tmp;
}
int lowbit(int x) {
    return x & (-x);
}
void add(int x, int y, int z) {
    for (; x <= n; x += lowbit(x)) {
        zxs[x] = update(zxs[x], y, z);
    }
}
int cnt1, cnt2, use1[N], use2[N];
void genlist(int x, int *a, int &p) {
    p = 0;
    for (; x; x -= lowbit(x)) {
        a[++p] = zxs[x];
    }
}
int query(int st, int ed, int k) {
    int lr = root[st - 1], rr = root[ed];
    genlist(ed, use1, cnt1);
    genlist(st - 1, use2, cnt2);
    int l = 1, r = p;
    while (l < r) {
        int mid = (l + r) >> 1, c = tr[tr[rr].l].sz - tr[tr[lr].l].sz;
        // printf("~~1~~~%d %d %d %d\n", l, r, c, k);
        for (int i = 1; i <= cnt1; i++)c += tr[tr[use1[i]].l].sz;
        for (int i = 1; i <= cnt2; i++)c -= tr[tr[use2[i]].l].sz;
        // printf("~~2~~~%d %d %d %d\n", l, r, c, k);
        if (c >= k) {
            for (int i = 1; i <= cnt1; i++)use1[i] = tr[use1[i]].l;
            for (int i = 1; i <= cnt2; i++)use2[i] = tr[use2[i]].l;
            rr = tr[rr].l;
            lr = tr[lr].l;
            r = mid;
        } else {
            for (int i = 1; i <= cnt1; i++)use1[i] = tr[use1[i]].r;
            for (int i = 1; i <= cnt2; i++)use2[i] = tr[use2[i]].r;
            rr = tr[rr].r;
            lr = tr[lr].r;
            l = mid + 1;
            k -= c;
        }
    }
    return l;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int t;
    scanf("%d", &t);
    while (t--) {
        tot = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];
            root[i] = 0;
        }
        p = n;
        char op[2];
        for (int i = 1; i <= m; i++) {
            scanf("%s", op);
            if (op[0] == 'Q') {
                q[i].op = 1;
                scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
            } else {
                q[i].op = 0;
                scanf("%d%d", &q[i].x, &q[i].y);
                b[++p] = q[i].y;
            }
        }
        sort(b + 1, b + p + 1);
        p = unique(b + 1, b + p + 1) - (b + 1);
        root[0] = build(1, p);
        for (int i = 1; i <= n; i++) {
            a[i] = get(a[i]);
            zxs[i] = root[0];
            root[i] = update(root[i - 1], a[i], 1);
        }
        for (int i = 1; i <= m; i++) {
            if (q[i].op) {
                printf("%d\n", b[query(q[i].x, q[i].y, q[i].z)]);
            } else {
                q[i].y = get(q[i].y);
                add(q[i].x, a[q[i].x], -1);
                add(q[i].x, q[i].y, 1);
                a[q[i].x] = q[i].y;
            }
        }
    }
    return 0;
}