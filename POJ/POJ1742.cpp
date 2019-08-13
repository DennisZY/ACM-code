#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <string>
#include <cmath>
#include <ctime>
#include <queue>
#include <map>
#include <set>
/*
#include <unordered_map>
#include <unordered_set>
*/
using namespace std;
bool f[100010];
int used[100010], a[110], c[110];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    while (scanf("%d%d", &n, &m), n && m) {
        for (int i = 1; i <= n; i++)scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)scanf("%d", &c[i]);
        for (int i = 1; i <= m; i++)f[i] = false;
        f[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++)used[j] = 0;
            for (int j = a[i]; j <= m; j++) {
                if (!f[j] && f[j - a[i]] && used[j - a[i]] < c[i]) {
                    f[j] = true, used[j] = used[j - a[i]] + 1;
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            if (f[i])ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}