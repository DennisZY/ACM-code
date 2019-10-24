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

const int N = 100010;
struct node {
    double x, y;
    node(double _x = 0.0, double _y = 0.0) : x(_x), y(_y) {}
    node operator+(const node &b) const { return node(x + b.x, y + b.y); }
    node operator-(const node &b) const { return node(x - b.x, y - b.y); }
    double operator*(const node &b) const { return x * b.y - y * b.x; }
    node operator*(const double &b) const { return node(x * b, y * b); }
    double operator^(const node &b) const { return x * b.x + y * b.y; }
    double len2() { return x * x + y * y; }
    node rot() { return node(-y, x); }
} no[N];
struct Line {
    node p, v;
    inline Line() {}
    inline Line(const node pp, const node vv) : p(pp), v(vv) {}
    friend node cross(const Line &a, const Line &b) {
        return a.p + a.v * (b.v * (b.p - a.p) / (b.v * a.v));
    }
};
node circle(const node &a, const node &b, const node &c) {
    return cross(Line((a + b) * 0.5, (b - a).rot()), Line((a + c) * 0.5, (c - a).rot()));
}
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lf%lf", &no[i].x, &no[i].y);
    random_shuffle(no + 1, no + n + 1);
    double r = 0;
    node o = node(0, 0);
    for (int i = 1; i <= n; i++) {
        if ((no[i] - o).len2() > r) {
            o = no[i], r = 0;
            for (int j = 1; j <= i - 1; j++) {
                if ((no[j] - o).len2() > r) {
                    o = (no[i] + no[j]) * 0.5, r = (no[j] - o).len2();
                    for (int k = 1; k <= j - 1; k++) {
                        if ((no[k] - o).len2() > r)
                            o = circle(no[i], no[j], no[k]), r = (no[k] - o).len2();
                    }
                }
            }
        }
    }
    printf("%.10lf\n", sqrt(r));
    printf("%.10lf %.10lf\n", o.x, o.y);
    return 0;
}