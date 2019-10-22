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
int b, n, d, m;

namespace task1 {
int a[100010];
void solve() {
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    ll ans = 0;
    sort(a + 1, a + n + 1);
    for (int i = 2, j = 1; i <= n; i++) {
        while (a[i] - a[j] > d) ++j;
        ans += i - j;
    }
    printf("%lld\n", ans);
}
}  // namespace task1
namespace task2 {
inline int lowbit(int x) { return x & (-x); }
int c[75010 << 1];

void add(int x, int y) {
    while (x <= 2 * m) {
        c[x] += y;
        x += lowbit(x);
    }
}
int sum(int x) {
    x = min(x, 2 * m);
    x = max(x, 0);
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}
struct node {
    int x, y;
    bool operator<(const node& tmp) const { return y < tmp.y; }
} no[100010];
void solve() {
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y);
        no[i].x = x + y;
        no[i].y = x - y;
    }
    sort(no + 1, no + n + 1);
    add(no[1].x, 1);
    ll ans = 0;
    for (int i = 2, j = 1; i <= n; i++) {
        while (no[i].y - no[j].y > d) {
            add(no[j].x, -1);
            ++j;
        }
        ans += sum(no[i].x + d) - sum(no[i].x - d - 1);
        add(no[i].x, 1);
    }
    printf("%lld\n", ans);
}
}  // namespace task2

namespace task3 {
int s[80][500][500];
struct node {
    int x, y, z;
} no[100010];
int get(int z, int x, int y, int d) {
    return s[z][x + d][y + d] + s[z][max(0, x - d - 1)][max(0, y - d - 1)] -
           s[z][x + d][max(0, y - d - 1)] - s[z][max(0, x - d - 1)][y + d];
}
void solve() {
    memset(s, 0, sizeof s);
    for (int i = 1, x, y, z; i <= n; i++) {
        scanf("%d%d%d", &x, &y, &z);
        no[i].x = x + y, no[i].y = x - y, no[i].z = z;
        ++s[z][no[i].x][no[i].y + 80];
    }
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m * 5 + 5; j++) {
            for (int k = -75; k <= m * 5 + 5; k++) {
                s[i][j][k + 80] = s[i][j][k + 80] + s[i][j - 1][k + 80] + s[i][j][k - 1 + 80] -
                                  s[i][j - 1][k - 1 + 80];
            }
        }
    }
    ll ans = 0;
    ll an = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < no[i].z; j++) {
            if (no[i].z - j <= d) {
                ans += get(j, no[i].x, no[i].y + 80, d - no[i].z + j);
            }
        }
        an += get(no[i].z, no[i].x, no[i].y + 80, d);
        an--;
    }
    printf("%lld\n", ans + (an >> 1));
}
}  // namespace task3

int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d%d%d", &b, &n, &d, &m);
    if (b == 1) {
        task1::solve();
    } else if (b == 2) {
        task2::solve();
    } else {
        task3::solve();
    }
    return 0;
}
