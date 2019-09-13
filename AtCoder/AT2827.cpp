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
const int N = 100010;
int a[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    memset(a, 0x3f, sizeof a);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        *lower_bound(a, a + n, x) = x;
    }
    printf("%d\n", lower_bound(a, a + n, 0x3f3f3f3f) - a);
    return 0;
}