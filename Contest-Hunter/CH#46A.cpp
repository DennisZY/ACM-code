#include <algorithm>
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
const int N = 250010;
const int T = 610;
typedef long long ll;
struct node {
    ll x, y, m, p, r;
    ll getdis();
} no[N];
ll node::getdis() {
    return (x - no[0].x) * (x - no[0].x) + (y - no[0].y) * (y - no[0].y);
}
int L[T], R[T], pos[N], M[T];
bool cmp1( node& a,  node& b) {
    return a.m < b.m;
}
bool cmp2( node& a,  node& b) {
    return a.getdis() < b.getdis();
}
bool check( node& a,  node& b) {
    return (no[0].x - b.x) * (no[0].x - b.x) + (no[0].y - b.y) * (no[0].y - b.y) <= a.r * a.r;
}
int vis[N];
int que[N];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    scanf("%lld%lld%lld%lld%d", &no[0].x, &no[0].y, &no[0].p, &no[0].r, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%lld%lld%lld", &no[i].x, &no[i].y, &no[i].m, &no[i].p, &no[i].r);
    }
    sort(no + 1, no + n + 1, cmp1);
    int t = sqrt(n);
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
        M[i] = no[R[i]].m;
        sort(no + L[i], no + R[i] + 1, cmp2);
    }
    int l = 0, r = 1;
    que[l] = 0;
    fill(vis + 1, vis + n + 1, 0);
    while (l < r) {
        int now = que[l];
        int k = 0;
        for (int i = 1; i <= t; i++) {
            if (no[now].p >= M[i])k = i;
            else break;
        }
        for (int i = 1; i <= k; i++) {
            while (L[i] <= R[i] && check(no[now], no[L[i]])) {
                if (!vis[L[i]]) {
                    vis[L[i]] = 1;
                    que[r++] = L[i];
                }
                ++L[i];
            }
        }
        if (t != k++) {
            for (int i = L[k]; i <= R[k]; i++) {
                if (!vis[i] && no[now].p >= no[i].m && check(no[now], no[i])) {
                    vis[i] = 1;
                    que[r++] = i;
                }
            }
        }
        l++;
    }
    printf("%d\n", r - 1);
    return 0;
}
