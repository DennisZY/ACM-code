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
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
const double PI = acos(-1.);
// mt19937 myrand(time(0));

const int N = 3010;
struct node {
    ll x, y;
    double k;
    int id;
    int c;
    bool operator<(const node& tmp) const { return k < tmp.k; }
} no[N];
int c[2][3], bl[N];
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld%d", &no[i].x, &no[i].y, &no[i].c);
        no[i].id = i;
    }
    ll ans = 0, res;
    for (int i = 1; i <= n; i++) {
        node tmp;
        for (int j = 1; j <= n; j++)
            if (no[j].id == i) {
                tmp = no[j];
                break;
            }
        for (int j = 1; j <= n; j++) {
            no[j].k = (no[j].id == i) ? 1e9 : atan2(no[j].y - tmp.y, no[j].x - tmp.x);
            if (no[j].k <= 0) no[j].k += PI;
        }
        sort(no + 1, no + n + 1);
        memset(c, 0, sizeof c);
        for (int j = 1; j <= n - 1; j++) {
            if (no[j].y < tmp.y || (no[j].y == tmp.y && no[j].x > tmp.x))
                ++c[bl[j] = 0][no[j].c];
            else
                ++c[bl[j] = 1][no[j].c];
        }
        int k = tmp.c;
        for (int j = 1; j <= n - 1; j++) {
            --c[bl[j]][no[j].c];
            res = 1;
            if (k) res *= c[0][0];
            if (k ^ 1) res *= c[0][1];
            if (k ^ 2) res *= c[0][2];
            if (no[j].c) res *= c[1][0];
            if (no[j].c ^ 1) res *= c[1][1];
            if (no[j].c ^ 2) res *= c[1][2];
            ans += res;
            res = 1;
            if (k) res *= c[1][0];
            if (k ^ 1) res *= c[1][1];
            if (k ^ 2) res *= c[1][2];
            if (no[j].c) res *= c[0][0];
            if (no[j].c ^ 1) res *= c[0][1];
            if (no[j].c ^ 2) res *= c[0][2];
            ans += res;
            ++c[bl[j] ^= 1][no[j].c];
        }
    }
    printf("%lld\n", ans >> 2);
    return 0;
}