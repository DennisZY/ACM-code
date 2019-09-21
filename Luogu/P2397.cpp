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

int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n;
    int now = 0, cnt = 0;
    scanf("%d", &n);
    for (int i = 1, m; i <= n; i++) {
        scanf("%d", &m);
        if (now == m) {
            cnt++;
        }
        if (cnt == 0) {
            now = m, cnt = 1;
        }
        if (now != m) {
            cnt--;
        }
    }
    printf("%d\n", now);
    return 0;
}
