#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> A(n + 1), pos(1), S(n + 1);
    rep(i, 1, n) cin >> A[i], S[i] = S[i - 1] + A[i];
    rep(i, 1, n) if(A[i] == 1) pos.emplace_back(i);
    vector<VI> F(n + 1, VI(k + 1));
    int B = sqrt(k) + 1;

    F[0][0] = 1;
    rep(i, 1, n) {
        per(j, min({S[i] + B, S[n], i}), max(1, S[i] - B)) {
            int x = abs(pos[j] - i);
            rep(a, x, k) (F[j][a] += F[j - 1][a - x]) %= mod;
        }
    }   
    int ans = 0;
    for(int i = k; i >= 0; i -= 2) (ans += F[S[n]][i]) %= mod;
    cout << ans << '\n';
    return 0;
}
