//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 998244353;

ll qpow(int x, int y) {
    ll ret = 1;
    while(y) {
        if(y & 1) ret = ret * x % mod;
        x = x * x % mod;
        y >>= 1; 
    } 
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<vector<char>> A(n + 1, vector<char>(m  + 1)); 
    int sum  =0;
    rep(i, 1, n) rep(j, 1, m) {
        cin >> A[i][j];
        if(A[i][j] == 'o') sum++;
    }
    vector<ll> F(max(n, m) + 1) ;
    rep(i, 2, max(n, m)) (F[i] = F[i - 1] + F[i - 2] * 2 % mod + qpow(2, i - 2)) %= mod; 
    ll ans = 0;
    rep(i, 1, n) {
        int cnt = 0;
        rep(j, 1, m) {
            if(A[i][j] == 'o') {
                cnt++;
            }
            else (ans += F[cnt] * qpow(2, sum - cnt)) %= mod, cnt = 0;
        }
        if(cnt > 0) (ans += F[cnt] * qpow(2, sum - cnt)) %= mod;
    }
    rep(j, 1, m) {
        int cnt = 0;
        rep(i, 1, n) {
            if(A[i][j] == 'o') {
                cnt++;
            }
            else (ans += F[cnt] * qpow(2, sum - cnt)) %= mod, cnt = 0;
        }
        if(cnt > 0) (ans += F[cnt] * qpow(2, sum - cnt)) %= mod;
    }
    cout << ans % mod << '\n';
    return 0;
}