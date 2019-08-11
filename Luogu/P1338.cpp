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
typedef long long ll;
const int N = 50010;
int a[N];
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n, m;
    scanf("%d%d", &n, &m);
    int l = 1, r = n;
    for (int i = 1; i <= n; i++) {
        ll cnt = (ll)(n - i) * (n - i - 1) / 2;
        if (cnt >= m)a[l++] = i;
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