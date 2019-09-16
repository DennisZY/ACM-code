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
const int N = 1010;
int a[N];
int b[N];
bool cmp(int x, int y) { return a[x] < a[y]; }
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        b[i] = i;
    }
    sort(b + 1, b + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        printf("%d%c", b[i], i == n ? '\n' : ' ');
    double ans = 0, res = 0;
    for (int i = 1; i <= n; i++) {
        ans += res / n;
        res += a[b[i]];
    }
    printf("%.2f\n", ans);
    return 0;
}