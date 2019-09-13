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
const int N = 1000006;
struct rec {
    int x, y, z, id;
    bool operator<(const rec &tmp) const
    {
        return x < tmp.x || (x == tmp.x && y < tmp.y);
    }
} a[N], b[N], tmp[N];
int c[N], tot;
int ans[N], n, m;

int ask(int x)
{
    int y = -(1 << 30);
    for (; x; x -= x & -x)
        y = max(y, c[x]);
    return y;
}

void insert(int x, int y)
{
    for (; x < tot; x += x & -x)
        c[x] = max(c[x], y);
}

void cal(int s, int e, int mid, int de, int dx, int dy)
{
    for (int i = s; i != e; i += de) {
        if ((b[i].z == 1 && b[i].id > mid) || (b[i].z == 2 && b[i].id <= mid))
            continue;
        int y = dy == 1 ? b[i].y : tot - b[i].y;
        int tmp = dx * b[i].x + dy * b[i].y;
        if (b[i].z == 1)
            insert(y, tmp);
        else
            ans[b[i].id] = min(ans[b[i].id], abs(tmp - ask(y)));
    }
    for (int i = s; i != e; i += de) {
        if ((b[i].z == 1 && b[i].id > mid) || (b[i].z == 2 && b[i].id <= mid))
            continue;
        int y = dy == 1 ? b[i].y : tot - b[i].y;
        if (b[i].z == 1) {
            for (int j = y; j < tot; j += j & -j)
                c[j] = -(1 << 30);
        }
    }
}
void CDQ(int l, int r)
{
    if (l == r) {
        b[l] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    if (l <= mid)
        CDQ(l, mid);
    if (mid < r)
        CDQ(mid + 1, r);
    int top = l, x = l, y = mid + 1;
    while (x <= mid && y <= r) {
        if (b[x] < b[y])
            tmp[top++] = b[x++];
        else
            tmp[top++] = b[y++];
    }
    while (x <= mid)
        tmp[top++] = b[x++];
    while (y <= r)
        tmp[top++] = b[y++];
    for (int i = l; i <= r; i++) {
        b[i] = tmp[i];
    }
    cal(l, r + 1, mid, 1, 1, 1);
    cal(r, l - 1, mid, -1, -1, -1);
    cal(l, r + 1, mid, 1, 1, -1);
    cal(r, l - 1, mid, -1, -1, 1);
}

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    tot = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i].y++;
        a[i].z = 1;
        a[i].id = i;
        if (tot < a[i].y)
            tot = a[i].y;
    }
    m += n;
    for (int i = n + 1; i <= m; i++) {
        scanf("%d%d%d", &a[i].z, &a[i].x, &a[i].y);
        a[i].y++;
        a[i].id = i;
        if (tot < a[i].y)
            tot = a[i].y;
    }
    ++tot;
    memset(c, 0xcf, sizeof c);
    memset(ans, 0x3f, sizeof ans);
    CDQ(1, m);
    for (int i = 1; i <= m; i++) {
        if (a[i].z == 2) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}