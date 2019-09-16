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
char encrypt[26];
bool vis[26];
const int N = 100010;
char s1[N], s2[N], s3[N];
int main()
{
    // freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    scanf("%s%s%s", s1, s2, s3);
    int flag = 1;
    int len = strlen(s1);
    for (int i = 0; i < len; i++) {
        s1[i] -= 'A';
        if (encrypt[s1[i]] == 0) {
            encrypt[s1[i]] = s2[i];
        } else if (encrypt[s1[i]] != s2[i]) {
            flag = 0;
            break;
        }
        vis[s2[i] - 'A'] = 1;
    }
    for (int i = 0; i < 26; i++) {
        if (encrypt[i] == 0 || vis[i] == false)
            flag = 0;
    }
    if (!flag) {
        puts("Failed");
    } else {
        len = strlen(s3);
        for (int i = 0; i < len; i++) {
            s3[i] -= 'A';
            if (encrypt[s3[i]] == 0) {
                flag = 0;
                break;
            } else {
                s3[i] = encrypt[s3[i]];
            }
        }
        if (flag) {
            puts(s3);
        } else
            puts("Failed");
    }
    return 0;
}