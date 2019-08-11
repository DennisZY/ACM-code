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
int x01, x02, y01, y02;
typedef long long ll;
ll mmp[30][30];
bool check(int x, int y) {
    return x >= 0 && x <= x01 && y >= 0 && y <= y01;
}
int main() {
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d%d%d%d", &x01, &y01, &x02, &y02);
    if (check(x02, y02))mmp[x02][y02] = -1;
    if (check(x02 + 1, y02 + 2))mmp[x02 + 1][y02 + 2] = -1;
    if (check(x02 + 1, y02 - 2))mmp[x02 + 1][y02 - 2] = -1;
    if (check(x02 - 1, y02 + 2))mmp[x02 - 1][y02 + 2] = -1;
    if (check(x02 - 1, y02 - 2))mmp[x02 - 1][y02 - 2] = -1;
    if (check(x02 + 2, y02 + 1))mmp[x02 + 2][y02 + 1] = -1;
    if (check(x02 + 2, y02 - 1))mmp[x02 + 2][y02 - 1] = -1;
    if (check(x02 - 2, y02 + 1))mmp[x02 - 2][y02 + 1] = -1;
    if (check(x02 - 2, y02 - 1))mmp[x02 - 2][y02 - 1] = -1;
    for (int i = 0; i <= x01; i++) {
        if (mmp[i][0] != -1)mmp[i][0] = 1;
        else break;
    }
    for (int i = 0; i <= y01; i++) {
        if (mmp[0][i] != -1)mmp[0][i] = 1;
        else break;
    }
    for (int i = 1; i <= x01; i++) {
        for (int j = 1; j <= y01; j++) {
            if (mmp[i][j] == -1)continue;
            if (mmp[i - 1][j] != -1)mmp[i][j] += mmp[i - 1][j];
            if (mmp[i][j - 1] != -1)mmp[i][j] += mmp[i][j - 1];
        }
    }
    printf("%lld\n", mmp[x01][y01]);
    return 0;
}