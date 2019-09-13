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
const int N = 1000010;
int a[N << 1], q[N << 1], pos[N << 1];
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        a[i + n] = a[i];
    }
    int res = n << 1;
    int l = 0, r = -1;
    q[++r] = a[1] - 1;
    pos[r] = 1;
    int len = n >> 1;
    int ans = 0;
    for (int i = 2; i <= res; i++) {
        while (l <= r && i - pos[l] > len) {
            ++l;
        }
        if (l <= r)
            ans = max(ans, a[i] + i + q[l]);
        while (l <= r && q[r] <= a[i] - i) {
            --r;
        }
        q[++r] = a[i] - i;
        pos[r] = i;
    }
    printf("%d\n", ans);
    return 0;
}
