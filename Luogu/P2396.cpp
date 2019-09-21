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

const int mod = 1000000007;
int b[30];
int dp[1 << 24];
int dis[1 << 24];
void upd(int &a, int b) { (a += b) >= mod && (a -= mod); }
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &dis[1 << i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    dp[0] = 1;
    int res = (1 << n) - 1;
    for (int i = 1; i <= res; i++) {
        int kk = i & (-i);
        dis[i] = dis[i ^ kk] + dis[kk];
        int flag = 1;
        for (int j = 0; j < m; j++) {
            if (dis[i] == b[j])
                flag = 0;
        }
        if (flag) {
            int j = i;
            for (int k; j; j ^= k) {
                k = j & (-j);
                upd(dp[i], dp[i ^ k]);
            }
        }
    }
    printf("%d\n", dp[res]);
    return 0;
}