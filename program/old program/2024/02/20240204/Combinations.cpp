//Combinations 

#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 100 + 5;

ll c[N][N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    c[1][0] = c[1][1] = 1;
    rep(i, 2, N - 1) {
        c[i][0] = c[i][i] = 1;
        rep(j, 1, i - 1) c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }
    for(int n, m; cin >> n >> m && n; ) 
        printf("%d things taken %d at a time is %lld exactly.\n", n, m, c[n][m]);
    return 0;
}