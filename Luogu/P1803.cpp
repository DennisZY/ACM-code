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
const int N = 1000000;
struct node {
    int a, b;
    bool operator<(const node &tmp) const
    {
        if (b != tmp.b)
            return b < tmp.b;
        else
            return a < tmp.a;
    }
} no[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d%d", &no[i].a, &no[i].b);
    }
    sort(no + 1, no + n + 1);
    int ans = 0, pre = 0;
    for (int i = 1; i <= n; i++) {
        if (no[i].a >= pre) {
            ans++;
            pre = no[i].b;
        }
    }
    printf("%d\n", ans);
    return 0;
}