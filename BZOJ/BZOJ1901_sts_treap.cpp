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
#include <random>
/*
#include <unordered_map>
#include <unordered_set>
*/
using namespace std;
const int N = 200006;
const int INF = 1e9;
mt19937 myrand(time(0));
char s[10];
struct query {
    int op, x, y, z;
} q[N];
struct treap {
    int l, r, rnd, num, sz;
} T[N * 20];
struct sgmt {
    int l, r, sz, root;
} tr[N << 3];
int a[N], b[N << 1];
int w, tot, n, m;
//treap
int newnode(int val) {
    ++tot;
    T[tot].sz = 1;
    T[tot].num = val;
    T[tot].rnd = myrand();
    return tot;
}
void pushup(int p) {
    T[p].sz = 1 + T[T[p].l].sz + T[T[p].r].sz;
}
void lrotate(int &p) {
    int t = T[p].r;
    T[p].r = T[t].l;
    T[t].l = p;
    pushup(p);
    pushup(t);
    p = t;
}
void rrotate(int &p) {
    int t = T[p].l;
    T[p].l = T[t].r;
    T[t].r = p;
    pushup(p);
    pushup(t);
    p = t;
}
void insert(int &p, int val) {
    if (!p) {
        p = newnode(val);
        return ;
    }
    if (val < T[p].num) {
        insert(T[p].l, val);
        if (T[p].rnd < T[T[p].l].rnd)rrotate(p);
    } else {
        insert(T[p].r, val);
        if (T[p].rnd < T[T[p].r].rnd)lrotate(p);
    }
    pushup(p);
}
void erase(int &p, int val) {
    if (!p) {
        return ;
    }
    if (val == T[p].num) {
        if (T[p].l == 0 || T[p].r == 0) {
            p = T[p].l + T[p].r;
            if (p == 0)return ;
        } else {
            if (T[T[p].l].rnd > T[T[p].r].rnd) {
                rrotate(p);
                erase(T[p].r, val);
            } else {
                lrotate(p);
                erase(T[p].l, val);
            }
        }
    } else if (val < T[p].num) {
        erase(T[p].l, val);
    } else {
        erase(T[p].r, val);
    }
    pushup(p);
}
int getrank(int p, int val) {
    int ans = 0;
    while (p) {
        if (T[p].num <= val) {
            ans += T[T[p].l].sz + 1;
            if (T[p].num == val)break;
            p = T[p].r;
        } else {
            p = T[p].l;
        }
    }
    return ans;
}
//sgmt
void build(int rt, int l, int r) {
    tr[rt].l = l;
    tr[rt].r = r;
    tr[rt].root = 0;
    tr[rt].sz = 0;
    if (l == r)return;
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void Add(int rt, int pos, int val) {
    insert(tr[rt].root, pos);
    tr[rt].sz++;
    if (tr[rt].l == tr[rt].r)return ;
    int mid = (tr[rt].l + tr[rt].r) >> 1;
    if (val <= mid) {
        Add(rt << 1, pos, val);
    } else {
        Add(rt << 1 | 1, pos, val);
    }
}
void del(int rt, int pos, int val) {

    erase(tr[rt].root, pos);
    tr[rt].sz--;
    if (tr[rt].l == tr[rt].r)return ;
    int mid = (tr[rt].l + tr[rt].r) >> 1;
    if (val <= mid) {
        del(rt << 1, pos, val);
    } else {
        del(rt << 1 | 1, pos, val);
    }
}
int query(int rt, int l, int r, int k) {
    while (tr[rt].l != tr[rt].r) {
        int c = getrank(tr[rt << 1].root, r) - getrank(tr[rt << 1].root, l - 1);
        if (c >= k) {
            rt = rt << 1;
        } else {
            k -= c;
            rt = rt << 1 | 1;
        }
    }
    return tr[rt].l;
}
int get(int val) {
    return lower_bound(b + 1, b + w + 1, val) - b;
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    srand(time(NULL));
    tot = 0;
    int p = 0;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[++p] = a[i];
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s", s);
        if (s[0] == 'Q') {
            q[i].op = 0;
            scanf("%d%d%d", &q[i].x, &q[i].y, &q[i].z);
        } else {
            q[i].op = 1;
            scanf("%d%d", &q[i].x, &q[i].y);
            b[++p] = q[i].y;
        }
    }
    sort(b + 1, b + p + 1);
    w = unique(b + 1, b + p + 1) - (b + 1);
    build(1, 1, w);
    for (int i = 1; i <= n; i++) {
        a[i] = get(a[i]);
        Add(1, i, a[i]);
    }
    for (int i = 1; i <= m; i++) {
        if (q[i].op == 1) {
            q[i].y = get(q[i].y);
            del(1, q[i].x, a[q[i].x]);
            Add(1, q[i].x, q[i].y);
            a[q[i].x] = q[i].y;
        } else {
            printf("%d\n", b[query(1, q[i].x, q[i].y, q[i].z)]);
        }
    }
    return 0;
}