#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 1e9 + 7;

namespace catalan {
    constexpr int N = 1e6 + 5;
    LL iv[N], C[N];
    void init() {
        iv[1] = 1;
        rep(i, 2, N - 1) iv[i] = 1ll * (mod - mod / i) * iv[mod % i] % mod;
        C[0] = C[1] = 1;
        rep(i, 2, N - 2) C[i] = C[i - 1] * 2 * (2 * i - 1) % mod * iv[i + 1] % mod;
    }
}using catalan::C;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    catalan::init();
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    
    int mx = *max_element(A.begin() + 1, A.end());
    vector<int> L(n + 1), F(mx + 1), stk(1, 0);
    rep(i, 1, n) {
        while(A[stk.back()] > A[i]) stk.pop_back();
        L[i] = stk.back(); stk.emplace_back(i);
    }

    LL ans = 1;
    rep(i, 1, n) {
        int &f = F[A[i]];
        if(A[L[i]] == A[i]) f++;
        else (ans *= C[f]) %= mod, f = 1;
    }

    for(auto f : F) (ans *= C[f]) %= mod;

    cout << ans << '\n';

    return 0;
}