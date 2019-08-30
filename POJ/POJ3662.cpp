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
const int N = 10010;
typedef long long ll;
int Head[N], ver[N << 1], nxt[N << 1], c[N << 1];
int tot;
void add(int x, int y, int z) {
    ver[++tot] = y;
    c[tot] = z;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
int n, p, k;
bool vis[N];
int d[N];
int check(int mid) {
    deque<int>q;
    q.push_front(1);
    memset(d, 0x3f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[1] = 0;
    while (q.size()) {
        int u = q.front();
        q.pop_front();
        if (vis[u])continue;
        vis[u] = 1;
        for (int i = Head[u], v; i; i = nxt[i]) {
            v = ver[i];
            if (vis[v])continue;
            if (c[i] > mid) {
                if (d[v] <= d[u] + 1) continue;
                d[v] = d[u] + 1;
                q.push_back(v);
            } else {
                if (d[v] <= d[u]) continue;
                d[v] = d[u];
                q.push_front(v);
            }
        }
    }
    return d[n];
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    tot = 0;
    scanf("%d%d%d", &n, &p, &k);
    int maxn = 0;
    for (int i = 1, x, y, z; i <= p; i++) {
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
        maxn = max(maxn, z);
    }
    if (check(maxn) > k) {
        puts("-1");
        exit(0);
    }
    int l = 0, r = maxn, mid;
    while (l < r) {
        mid = (l + r) >> 1;
        if (check(mid) > k) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    printf("%d\n", l);
    return 0;
}