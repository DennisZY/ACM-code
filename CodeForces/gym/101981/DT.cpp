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
const int N = 110;
const double eps = 1e-6;
int n;
struct node {
    double x, y, z;
    node(double _x = 0.0, double _y = 0.0, double _z = 0.0) : x(_x), y(_y), z(_z) {}
} no[N];
double dis(const node& a, const node& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}
double cal(const node& a) {
    double ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dis(a, no[i]));
    }
    return ans;
}
double x = 0, y = 0, z = 0;
double ans;
double solve1() {
    double T = 100000;
    while (T > 1e-9) {
        double X = x + 1.0 * (((1ll * rand()) << 1) - RAND_MAX) / (RAND_MAX)*T;
        double Y = y + 1.0 * (((1ll * rand()) << 1) - RAND_MAX) / (RAND_MAX)*T;
        double Z = z + 1.0 * (((1ll * rand()) << 1) - RAND_MAX) / (RAND_MAX)*T;
        // printf("x=%lf y=%lf z=%lf\n", x, y, z);
        // printf("X=%lf Y=%lf z=%lf\n", X, Y, Z);
        double now = cal(node(X, Y, Z));
        double delta = now - ans;
        if (delta < 0) {
            x = X, y = Y, z = Z;
            // printf("%lf %lf %lf\n", x, y, z);
            ans = now;
        }
        // else if (exp(-delta / T) * RAND_MAX > rand()) {
        //     x = X, y = Y, z = Z;
        // }
        T *= 0.98;
    }
    return ans;
}
double solve() {
    ans = cal(node(0, 0, 0));
    x = 0, y = 0, z = 0;
    solve1();
    solve1();
    solve1();
    return ans;
}
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    srand(time(0));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf%lf", &no[i].x, &no[i].y, &no[i].z);
    }
    printf("%.5lf\n", solve());
    return 0;
}