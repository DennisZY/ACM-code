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
int n;
int sg[5010];
bool f[5010];
void getsg()
{
    sg[2] = 1;
    for (int i = 3; i <= 5000; i++) {
        memset(f, 0, sizeof f);
        for (int j = 0; j <= i - 2; j++) {
            f[sg[j] ^ sg[i - j - 2]] = 1;
        }
        int t = 0;
        while (f[t])
            ++t;
        sg[i] = t;
    }
}
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    getsg();
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        puts(sg[n] ? "First" : "Second");
    }
    return 0;
}