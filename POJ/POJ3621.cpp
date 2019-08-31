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
const int L = 1010;
const int P = 5010;
int n, m;
int f[L];
int from[P], to[P], w[P];
int Head[L], ver[P << 1], nxt[P << 1], tot;
double c[P << 1];
void add(int x, int y, double z) {
    ver[++tot] = y;
    c[tot] = z;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
int cnt[L];
double d[L];
bool vis[L];
bool spfa() {
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
        vis[i] = true;
        cnt[i] = d[i] = 0;
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for (int i = Head[u], v; i; i = nxt[i]) {
            v = ver[i];
            if (d[v] > d[u] + c[i]) {
                d[v] = d[u] + c[i];
                if (++cnt[v] > n)return 1;
                if (!vis[v]) {
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
    }
    return 0;
}
bool check(double res) {
    tot = 0;
    fill(Head, Head + n + 1, 0);
    for (int i = 1; i <= m; i++) {
        add(from[i], to[i], res * w[i] - f[from[i]]);
    }
    return spfa();
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &f[i]);
    }
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d", &from[i], &to[i], &w[i]);
    }
    double l = 0, r = 1000, mid;
    while (l + 1e-6 < r) {
        mid = (l + r) / 2;
        if (check(mid))l = mid;
        else r = mid;
    }
    printf("%.2f\n", l);
    return 0;
}