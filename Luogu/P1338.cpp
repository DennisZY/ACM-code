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
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;
typedef long long ll;
const int N = 50010;
int a[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        ll cnt = (ll)(n - i) * (n - i - 1) / 2;
        if (cnt >= m)
            a[l++] = i;
        else {
            a[r--] = i;
            m -= (n - i);
        }
    }
    for (int i = 1; i <= n; i++) {
        printf("%d%c", a[i], i == n ? '\n' : ' ');
    }

    return 0;
}