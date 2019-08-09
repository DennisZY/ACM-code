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
const int N = 1000010;
int p, prime[N], v[N];
int pre[N];
void pj() {
    int n = 1000000;
    int pr = 0;
    for (int i = 2; i <= n; i++) {
        if (v[i] == 0) {
            v[i] = i;
            prime[pr++] = i;
        }
        for (int j = 0; j < pr && n / i >= prime[j]; j++) {
            v[i * prime[j]] = prime[j];
            if (v[i] <= prime[j])break;
        }
    }
}
int main() {
    pj();
    pre[0] = 0;
    for (int i = 1; i <= 1000000; i++) {
        if (v[i] == i) {
            pre[i] = pre[i - 1] + 1;
        } else {
            pre[i] = pre[i - 1];
        }
    }
    int n, m;
    scanf("%d%d", &n, &m);
    while (n--) {
        int l, r;
        scanf("%d%d", &l, &r);
        if (l < 1 || r < 1 || l > m || r > m)puts("Crossing the line");
        else {
            printf("%d\n", pre[r] - pre[l - 1]);
        }
    }
    return 0;
}
