#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<VI> F(n + 1, VI(n + 1));
    rep(i, 1, n) F[i][i] = F[i][1] = 1;
    rep(i, 2, n) rep(j, 2, i - 1) F[i][j] = F[i - 1][j] * j + F[i - 1][j - 1] * (i - j + 1);
    cout << F[n][k] << '\n'; 
    return 0;
}
/*
F[i][j] 1 - i 拥有 j 个上升段的个数
F[i][1] = F[i][i] = 1;
F[3][1] = 1, F[3][3] = 1; F[3][2] = 4;
*/
