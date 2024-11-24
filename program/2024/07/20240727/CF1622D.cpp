#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long ;
using VI = vector<int>;
constexpr int N = 5000 + 5, mod = 998244353;

LL qpow(LL x, LL y) {
    LL ret = 1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}

LL C[N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    string s; cin >> s; s = " " + s ;
    if(k == 0) return cout << "1\n", 0;
    vector<int> A(1);
    rep(i, 1, n) if(s[i] == '1') 
        A.push_back(i);
    int ans = 0;
    A.push_back(n + 1);
    if((int)A.size() - 2 < k) return cout << "1\n", 0;

    rep(i, 0, n) {
        C[i][0] = C[i][i] = 1;
        rep(j, 1, i - 1)
            (C[i][j] += C[i - 1][j] + C[i - 1][j - 1]) %= mod;
    }
    
    for(int i = 0; i + k + 1 < A.size(); i++) {
        (ans += C[A[i + k + 1] - A[i] - 1][k]) %= mod;
    }   
    for(int i = 1; i + k + 1 < A.size(); i++) 
        ((ans -= C[A[i + k] - A[i] - 1][k - 1]) += mod) %= mod;
    cout << ans << '\n';
    return 0;
}