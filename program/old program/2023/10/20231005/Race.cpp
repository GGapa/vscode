/*
Race, UVa12034
https://vjudge.csgrandeur.cn/contest/584215#problem/A
*/
#include <iostream>
using namespace std;
const int maxn = 1e3 + 5;
const int mod = 10056;

int  T, n;
int f[maxn][maxn];

void init() {
    for(int i = 1; i <= maxn - 5; i++) f[i][1] = 1;
    for(int i = 2; i <= maxn - 5; i++) for(int j = 1; j <= i; j++) 
        f[i][j] = (f[i - 1][j - 1] * j + f[i - 1][j] * j) % mod;
}

int main() {
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> T;
    init();
    int it = 1;
    while(T--) {
        cin >> n;
        int ans = 0;
        for(int i = 1; i <= n; i++) ans = (ans + f[n][i]) % mod; //取模写挂了
        printf("Case %d: %d\n", it++, ans);
    }
    return 0;
}