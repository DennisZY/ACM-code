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
const int N = 600005;
int n, m, tot;
int s[N], root[N], trie[N * 24][2], latest[N * 24];
char op[10];
void add(int i, int k, int p, int q)
{
    if (k < 0) {
        latest[q] = i;
        return;
    }
    int c = s[i] >> k & 1;
    if (p)
        trie[q][c ^ 1] = trie[p][c ^ 1];
    trie[q][c] = ++tot;
    add(i, k - 1, trie[p][c], trie[q][c]);
    latest[q] = max(latest[trie[q][0]], latest[trie[q][1]]);
}
int query(int now, int val, int k, int limit)
{
    while (k >= 0) {
        int c = val >> k & 1;
        if (latest[trie[now][c ^ 1]] >= limit) {
            now = trie[now][c ^ 1];
        } else {
            now = trie[now][c];
        }
        --k;
    }
    return s[latest[now]] ^ val;
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d", &n, &m);
    latest[0] = -1;
    root[0] = ++tot;
    add(0, 23, 0, root[0]);
    s[0] = 0;
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        s[i] = s[i - 1] ^ x;
        root[i] = ++tot;
        add(i, 23, root[i - 1], root[i]);
    }
    for (int i = 1; i <= m; i++) {
        scanf("%s", op);
        if (op[0] == 'A') {
            int x;
            scanf("%d", &x);
            root[++n] = ++tot;
            s[n] = s[n - 1] ^ x;
            add(n, 23, root[n - 1], root[n]);
        } else {
            int l, r, x;
            scanf("%d%d%d", &l, &r, &x);
            printf("%d\n", query(root[r - 1], x ^ s[n], 23, l - 1));
        }
    }
    return 0;
}