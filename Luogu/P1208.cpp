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
const int N = 5010;
ll n;
int m;
struct node {
    int p;
    ll a;
    bool operator<(const node &x) const { return p < x.p; }
} no[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> no[i].p >> no[i].a;
    }
    sort(no + 1, no + m + 1);
    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        if (!n)
            break;
        ll tmp = min(n, (long long)no[i].a);
        ans += tmp * no[i].p;
        n -= tmp;
    }
    cout << ans << endl;
    return 0;
}