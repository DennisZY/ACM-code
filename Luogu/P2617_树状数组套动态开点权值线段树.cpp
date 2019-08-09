// luogu-judger-enable-o2
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
const int N = 100010;
struct sgmt {
    int l, r, sz;
} tr[50000010];
struct rec {
    int op, x, y, z;
} q[N];
int root[N];
int tot, n, m, p;
int a[N], b[N << 1];
int get(int val) {
    return lower_bound(b + 1, b + p + 1, val) - b;
}
int newnode() {
    ++tot;
    tr[tot].l = tr[tot].r = tr[tot].sz = 0;
    return tot;
}
void update(int &p, int l, int r, int val, int cnt) {
    if (!p)p = newnode();
    tr[p].sz += cnt;
    if (l == r)return ;
    int mid = (l + r) >> 1;
    if (val <= mid) {
        update(tr[p].l, l, mid, val, cnt);
    } else {
        update(tr[p].r, mid + 1, r, val, cnt);
    }
}
inline int lowbit(int x) {
    return x & (-x);
}
void add(int x, int y, int z) {
    for (; x <= n; x += lowbit(x)) {
        update(root[x], 1, p, y, z);
    }
}
int cnt1, cnt2, use1[N], use2[N];
void genlist(int x, int *a, int &p) {
    p = 0;
    for (; x; x -= lowbit(x)) {
        a[++p] = root[x];
    }
}
int query(int l, int r, int k) {
    while (l < r) {
        int mid = (l + r) >> 1, c = 0;
        for (int i = 1; i <= cnt1; i++)c += tr[tr[use1[i]].l].sz;
        for (int i = 1; i <= cnt2; i++)c -= tr[tr[use2[i]].l].sz;
        if (c >= k) {
            for (int i = 1; i <= cnt1; i++)use1[i] = tr[use1[i]].l;
            for (int i = 1; i <= cnt2; i++)use2[i] = tr[use2[i]].l;
            r = mid;
        } else {
            for (int i = 1; i <= cnt1; i++)use1[i] = tr[use1[i]].r;
            for (int i = 1; i <= cnt2; i++)use2[i] = tr[use2[i]].r;
            l = mid + 1;
            k -= c;
        }
    }
    return l;
}

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    tot = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
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
    for (int i = 1; i <= n; i++) {
        a[i] = get(a[i]);
        add(i, a[i], 1);
    }
    for (int i = 1; i <= m; i++) {
        if (q[i].op) {
            genlist(q[i].y, use1, cnt1);
            genlist(q[i].x - 1, use2, cnt2);
            printf("%d\n", b[query(1, p, q[i].z)]);
        } else {
            q[i].y = get(q[i].y);
            add(q[i].x, a[q[i].x], -1);
            add(q[i].x, q[i].y, 1);
            a[q[i].x] = q[i].y;
        }
    }
    return 0;
}