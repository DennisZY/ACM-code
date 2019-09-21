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
int check[4][30];
int ans[20];
int n, tot;
void dfs(int pos)
{
    if (pos == n + 1) {
        ++tot;
        if (tot <= 3) {
            for (int i = 1; i <= n; i++) {
                printf("%d%c", ans[i], i == n ? '\n' : ' ');
            }
        }
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (!check[0][i] && !check[1][pos + i] && !check[2][i - pos + 13]) {
            check[0][i] = 1;
            check[1][pos + i] = 1;
            check[2][i - pos + 13] = 1;
            ans[pos] = i;
            dfs(pos + 1);
            check[0][i] = 0;
            check[1][pos + i] = 0;
            check[2][i - pos + 13] = 0;
        }
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%d", &n);
    tot = 0;
    dfs(1);
    printf("%d\n", tot);
    return 0;
}