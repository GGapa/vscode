#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int N = 15;

ll F[N][11][N][2100];

ll dp(int i, int j, int k, bool p, int sum, string &s) {
    // cout << i << " " << j << " "<< k << " " << p << " " << sum  << '\n';
    if(i < 0) return sum + j * k * k;
    auto &f = F[i][j][k][sum];
    if(f != -1 && p) return f;
    int mx = p ? 9 : s[i] - '0';
    ll ret = 0;
    rep(x, 0, mx) {
        ret += dp(i - 1, x, x == j ? k + 1 : 1, p || x < mx, x == j ? sum : sum + 1ll * j * k * k, s);
    }
    if(p) f = ret;
    return ret;
} 


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    ll a, b; cin >> a >> b;
    string A = to_string(a - 1), B = to_string(b);
    memset(F, -1, sizeof(F));
    reverse(B.begin(), B.end());
    ll u = dp(B.size() - 1, 10, 0, 0, 0, B);
    memset(F, -1, sizeof(F));
    reverse(A.begin(), A.end());
    ll t = dp(A.size() - 1, 10, 0, 0, 0, A);
    cout << u - t << '\n';
    return 0;
}

/*
考虑数位 DP
F(i, j, k, sum, p) 填充了 i 位,最后一位是 j,连续了 k 次的贡献值为 sum ,是否保证小于这个数字.
*/