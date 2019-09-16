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

const int N = 30010;
int w, n, a[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d%d", &w, &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1, [](int x, int y) { return x > y; });
    int l = 1, r = n;
    int ans = 0;
    while (l <= r) {
        if (l != r && a[l] + a[r] > w) {
            l++;
        } else if (l != r && a[l] + a[r] <= w) {
            l++, r--;
        } else {
            l++;
        }
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}