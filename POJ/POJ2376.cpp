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
const int N = 50010;
struct sgmt {
    int l, r, minn;
} no[N << 3];
struct query {
    int x, y;
    bool operator <(const query& tmp)const {
        return y < tmp.y;
    }
} q[N];
int b[N << 1], top;
int get(int val) {
    return lower_bound(b + 1, b + top + 1, val) - b;
}
void push_up(int p) {
    no[p].minn = min(no[p << 1].minn, no[p << 1 | 1].minn);
}
void build(int p, int l, int r) {
    no[p].l = l, no[p].r = r, no[p].minn = 0x3f3f3f3f;
    if (l == r)return ;
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}
void update(int p, int l, int c) {
    if (no[p].l == l && no[p].r == l) {
        no[p].minn = min(no[p].minn, c);
        return ;
    }
    int mid = (no[p].l + no[p].r) >> 1;
    if (l <= mid) {
        update(p << 1, l, c);
    } else {
        update(p << 1 | 1, l, c);
    }
    push_up(p);
}
int query(int p, int l, int r) {
    if (l <= no[p].l && no[p].r <= r) {
        return no[p].minn;
    }
    int mid = (no[p].l + no[p].r) >> 1;
    int ans = 0x3f3f3f3f;
    if (l <= mid) {
        ans = min(ans, query(p << 1, l, r));
    }
    if (mid < r) {
        ans = min(ans, query(p << 1 | 1, l, r));
    }
    return ans;
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, t;
    top = 0;
    scanf("%d%d", &n, &t);
    b[++top] = t;
    b[++top] = 0;
    b[++top] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &q[i].x, &q[i].y);
        b[++top] = q[i].x;
        b[++top] = q[i].x - 1;
        b[++top] = q[i].y;
        b[++top] = q[i].y - 1;
    }
    sort(b + 1, b + top + 1);
    top = unique(b + 1, b + top + 1) - (b + 1);
    while (b[top] > t)--top;
    sort(q + 1, q + n + 1);
    int res = get(t);
    for (int i = 1; i <= n; i++) {
        q[i].x = get(q[i].x);
        q[i].y = get(q[i].y);
        //printf("%d  %d\n", q[i].x, q[i].y);
    }
    build(1, 1, top);
    update(1, get(0), 0);
    for (int i = 1; i <= n; i++) {
        update(1, q[i].y, query(1, q[i].x - 1, q[i].y - 1) + 1);
    }
    int ans = query(1, res, res);
    if (ans != 0x3f3f3f3f) {
        printf("%d\n", ans);
    } else {
        puts("-1");
    }
    return 0;
}