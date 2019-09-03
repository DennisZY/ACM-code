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
#include <stack>
#include <map>
#include <set>
/*
#include <unordered_map>
#include <unordered_set>
*/
using namespace std;
const int N = 1010;
const int M = 1000000;
int tot, Head[N << 1], nxt[M << 2], ver[M << 2];
void add(int x, int y) {
    ver[++tot] = y;
    nxt[tot] = Head[x];
    Head[x] = tot;
}
int n, m;
char s[10];
int cnt, num, dfn[N << 1], low[N << 1], c[N << 1];
int sta[N << 1], insta[N << 1], top;
void tarjan(int u) {
    dfn[u] = low[u] = ++num;
    sta[++top] = u;
    insta[u] = 1;
    for (int i = Head[u], v; i; i = nxt[i]) {
        v = ver[i];
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (insta[v])
            low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        ++cnt;
        int v;
        do {
            v = sta[top--];
            insta[v] = 0;
            c[v] = cnt;
        } while (u != v);
    }
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1, x, y, z; i <= m; i++) {
        scanf("%d%d%d%s", &x, &y, &z, s);
        if (s[0] == 'X') {
            if (z) {
                add(x, y + n);
                add(x + n, y);
                add(y, x + n);
                add(y + n, x);
            } else {
                add(x, y);
                add(x + n, y + n);
                add(y, x);
                add(y + n, x + n);
            }
        } else if (s[0] == 'A') {
            if (z) {
                add(x, x + n);
                add(y, y + n);
            } else {
                add(x + n, y);
                add(y + n, x);
            }
        } else {
            if (z) {
                add(x, y + n);
                add(y, x + n);
            } else {
                add(x + n, x);
                add(y + n, y);
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (!dfn[i])tarjan(i);
    }
    for (int i = 0; i < n; i++) {
        if (c[i] == c[i + n]) {
            puts("NO");
            exit(0);
        }
    }
    puts("YES");
    return 0;
}