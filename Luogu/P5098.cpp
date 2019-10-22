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
const int N = 50010;
int minx, maxx, miny, maxy;
int main() {
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    miny = minx = 0x3f3f3f3f, maxy = maxx = 0;
    int n;
    scanf("%d", &n);
    for (int i = 1, x, y; i <= n; i++) {
        scanf("%d%d", &x, &y);
        minx = min(minx, x + y);
        maxx = max(maxx, x + y);
        miny = min(miny, x - y);
        maxy = max(maxy, x - y);
    }
    printf("%d\n", max(maxx - minx, maxy - miny));
    return 0;
}