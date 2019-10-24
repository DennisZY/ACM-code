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
#include <vector>
using namespace std;
typedef long long ll;
const double PI = acos(-1.);
// mt19937 myrand(time(0));

const int N = 110;
struct node {
    int x, y;
} no[N];

int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int t, kase = 0;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &no[i].x, &no[i].y);
            no[i].x += no[i - 1].x;
            no[i].y += no[i - 1].y;
        }
        int lp = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            int a = i, b = i + 1;
            if (b == n + 1) b = 1;
            int dx = no[a].x - no[b].x, dy = no[a].y - no[b].y;
            if (dx < 0) dx = -dx;
            if (dy < 0) dy = -dy;
            lp += __gcd(dx, dy);
            sum += no[a].x * no[b].y - no[a].y * no[b].x;
        }
        if (sum < 0) sum = -sum;
        printf("Scenario #%d:\n", ++kase);

        printf("%d %d %.1f\n", (sum - lp + 2) >> 1, lp, sum * 0.5);
        if (t) puts("");
    }
    return 0;
}
