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
int n, k;
const int N = 100010;
struct rec {
    int x, y, z, ans, w;
    bool operator<(const rec &tmp) const
    {
        if (y != tmp.y)
            return y < tmp.y;
        else
            return z < tmp.z;
    }
    bool operator==(const rec &tmp) const
    {
        return x == tmp.x && y == tmp.y && z == tmp.z;
    }
} b[N], tmp[N];
bool cmpx(const rec &a, const rec &b)
{
    if (a.x != b.x)
        return a.x < b.x;
    else if (a.y != b.y)
        return a.y < b.y;
    else
        return a.z < b.z;
}
int c[N << 1], ans[N];
void add(int x, int y)
{
    for (; x <= k; x += x & (-x)) {
        c[x] += y;
    }
}
int sum(int x)
{
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= x & (-x);
    }
    return ans;
}
void solve(int l, int r)
{
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);
    int i, j;
    for (i = mid + 1, j = l; i <= r; i++) {
        while (j <= mid && b[j].y <= b[i].y) {
            add(b[j].z, b[j].w);
            j++;
        }
        b[i].ans += sum(b[i].z);
    }
    while (j > l) {
        --j;
        add(b[j].z, -b[j].w);
    }
    int pl = l, pr = mid + 1, p = l;
    while (pl <= mid && pr <= r) {
        if (b[pl] < b[pr]) {
            tmp[p++] = b[pl++];
        } else {
            tmp[p++] = b[pr++];
        }
    }
    while (pl <= mid)
        tmp[p++] = b[pl++];
    while (pr <= r)
        tmp[p++] = b[pr++];
    for (int i = l; i <= r; i++)
        b[i] = tmp[i];
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d%d", &b[i].x, &b[i].y, &b[i].z);
        b[i].ans = 0;
        b[i].w = 1;
    }
    sort(b + 1, b + n + 1, cmpx);
    int top = 1;
    for (int i = 2; i <= n; i++) {
        if (b[i - 1] == b[i]) {
            b[top].w++;
        } else {
            b[++top] = b[i];
        }
    }
    solve(1, top);
    for (int i = 1; i <= top; i++) {
        ans[b[i].ans + b[i].w - 1] += b[i].w;
    }
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}