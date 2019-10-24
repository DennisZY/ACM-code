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
const double EE = 0.6180339887498949;
const int N = 110;
struct node {
    double x, y, z;
} no[N];
int n;
double cal(double x, double y, double z) {
    double ans = 0, xx, yy, zz;
    for (int i = 1; i <= n; i++) {
        xx = x - no[i].x, yy = y - no[i].y, zz = z - no[i].z;
        ans = max(ans, sqrt(xx * xx + yy * yy + zz * zz));
    }
    return ans;
}
double cal(double x, double y) {
    double ans = 1e9;
    double l = -100000, r = 100000, mid1, mid2;
    mid1 = l + (1 - EE) * (r - l);
    mid2 = mid1 + (1 - EE) * (r - mid1);
    for (int i = 1; i <= 100; i++) {
        double L = cal(x, y, mid1), R = cal(x, y, mid2);
        if (L > R) {
            l = mid1;
            mid1 = mid2;
            mid2 = mid1 + (1 - EE) * (r - mid1);
        } else {
            r = mid2;
            mid2 = mid1;
            mid1 = l + (1 - EE) * (r - l);
        }
        ans = min(ans, L);
        ans = min(ans, R);
    }
    return ans;
}
double cal(double x) {
    double ans = 1e9;
    double l = -100000, r = 100000, mid1, mid2;
    mid1 = l + (1 - EE) * (r - l);
    mid2 = mid1 + (1 - EE) * (r - mid1);
    for (int i = 1; i <= 100; i++) {
        double L = cal(x, mid1), R = cal(x, mid2);
        if (L > R) {
            l = mid1;
            mid1 = mid2;
            mid2 = mid1 + (1 - EE) * (r - mid1);
        } else {
            r = mid2;
            mid2 = mid1;
            mid1 = l + (1 - EE) * (r - l);
        }
        ans = min(ans, L);
        ans = min(ans, R);
    }
    return ans;
}
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);

    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf%lf%lf", &no[i].x, &no[i].y, &no[i].z);
    }
    double ans = 1e9;
    double l = -100000, r = 100000, mid1, mid2;
    mid1 = l + (1 - EE) * (r - l);
    mid2 = mid1 + (1 - EE) * (r - mid1);
    for (int i = 1; i <= 100; i++) {
        double L = cal(mid1), R = cal(mid2);
        if (L > R) {
            l = mid1;
            mid1 = mid2;
            mid2 = mid1 + (1 - EE) * (r - mid1);
        } else {
            r = mid2;
            mid2 = mid1;
            mid1 = l + (1 - EE) * (r - l);
        }
        ans = min(ans, L);
        ans = min(ans, R);
    }
    printf("%.15f\n", ans);
    return 0;
}