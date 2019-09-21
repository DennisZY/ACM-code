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
int a[N], n;
int num[N];
int ans[N][2];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    num[n] = 1, num[n - 1] = 2;
    int flag = (a[n - 1] <= a[n]) ? 1 : 0;
    for (int i = n - 2; i >= 1; i--) {
        if (a[i] <= a[i + 1]) {
            if (flag) {
                num[i] = num[i + 1] + 1;
            } else {
                flag = 1, num[i] = 2;
            }
        } else {
            if (flag) {
                flag = 0, num[i] = 2;
            } else {
                num[i] = num[i + 1] + 1;
            }
        }
    }
    int m;
    scanf("%d", &m);
    while (m--) {
        int k;
        scanf("%d", &k);
        if (ans[k][0] != 0) {
            printf("%d %d\n", ans[k][0], ans[k][1]);
            continue;
        }
        int now = 1;
        int subarr = 0, badcnt = 0;
        while (now + k - 1 <= n) {
            ++subarr;
            if (num[now] < k) {
                badcnt += k - num[now];
                now += k;
            } else {
                now += num[now];
            }
        }
        if (now <= n) {
            ++subarr;
            badcnt += n - (now + num[now] - 1);
        }
        printf("%d %d\n", ans[k][0] = subarr, ans[k][1] = badcnt);
    }

    return 0;
}