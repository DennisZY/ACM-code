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
const int M = 50010;
int Head[N], ver[M << 1], nxt[M << 1], tot;
void add(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
int t;
int sta[M << 1], ans[M << 1];
void euler() {
    int top = 0;
    t = 0;
    sta[++top] = 1;
    while (top > 0) {
        int u = sta[top], i = Head[u];
        if (i) {
            sta[++top] = ver[i];
            Head[u] = nxt[i];
        } else {
            top--;
            ans[++t] = u;
        }
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y; i <= m; i++) {
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }
    euler();
    for (int i = t; i; i--) {
        printf("%d\n", ans[i]);
    }
    return 0;
}