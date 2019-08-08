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

int n;
const int maxn = 100010;
struct treap {
    int l[maxn], r[maxn], val[maxn], rnd[maxn], size[maxn], w[maxn];
    int sz, ans, rt;
    void init() {
        sz = size[0] = w[0] = 0;
    }
    inline void pushup(int x) {
        size[x] = size[l[x]] + size[r[x]] + w[x];
    }
    void lrotate(int &k) {
        int t = r[k];
        r[k] = l[t];
        l[t] = k;
        size[t] = size[k];
        pushup(k);
        k = t;
    }
    void rrotate(int &k) {
        int t = l[k];
        l[k] = r[t];
        r[t] = k;
        size[t] = size[k];
        pushup(k);
        k = t;
    }
    void insert(int &k, int x) {
        if (k == 0) {
            k = ++sz;
            l[sz] = r[sz] = 0;
            val[sz] = x;
            rnd[sz] = rand();
            w[sz] = size[sz] = 1;
            return ;
        }
        ++size[k];
        if (x == val[k]) {
            ++w[k];
            return ;
        } else if (x < val[k]) {
            insert(l[k], x);
            if (rnd[k] < rnd[l[k]])rrotate(k);
        } else {
            insert(r[k], x);
            if (rnd[k] < rnd[r[k]])lrotate(k);
        }
    }
    void del(int &k, int x) {
        if (k == 0)return ;
        if (val[k] == x) {
            if (w[k] > 1) {
                --w[k];
                pushup(k);
                return ;
            }
            if (l[k] == 0 || r[k] == 0) {
                k = l[k] + r[k];
            } else if (rnd[l[k]] > rnd[r[k]]) {
                rrotate(k);
                del(r[k], x);
            } else {
                lrotate(k);
                del(l[k], x);
            }
        } else if (x < val[k]) {
            del(l[k], x);
        } else {
            del(r[k], x);
        }
        pushup(k);
    }
    int queryrank(int k, int x) {
        int ans = 0;
        while (k) {
            if (x == val[k]) {
                return ans + size[l[k]] + 1;
            } else if (x < val[k]) {
                k = l[k];
            } else {
                ans += size[l[k]] + w[k];
                k = r[k];
            }
        }
        if (!k)return 0;
        return ans;
    }
    int querynum(int k, int x) {
        if (x > size[rt])return 0;
        while (k) {
            if (size[l[k]] >= x) {
                k = l[k];
            } else if (x <= size[l[k]] + w[k]) {
                return val[k];
            } else {
                x -= size[l[k]] + w[k];
                k = r[k];
            }
        }
        return 0;
    }
    void querypre(int k, int x) {
        while (k) {
            if (val[k] < x) {
                ans = k;
                k = r[k];
            } else {
                k = l[k];
            }
        }
    }
    void querysub(int k, int x) {
        while (k) {
            if (val[k] > x) {
                ans = k;
                k = l[k];
            } else {
                k = r[k];
            }
        }
    }
} T;

int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    srand(time(0));
    scanf("%d", &n);
    int opt, x;
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &opt, &x);
        //printf("     %d\n", T.rt);
        if (opt == 1)
            T.insert(T.rt, x);
        else if (opt == 2)
            T.del(T.rt, x);
        else if (opt == 3) {
            printf("%d\n", T.queryrank(T.rt, x));
        } else if (opt == 4) {
            printf("%d\n", T.querynum(T.rt, x));
        } else if (opt == 5) {
            T.ans = 0;
            T.querypre(T.rt, x);
            printf("%d\n", T.val[T.ans]);
        } else if (opt == 6) {
            T.ans = 0;
            T.querysub(T.rt, x);
            printf("%d\n", T.val[T.ans]);
        }
    }
    return 0;
}
