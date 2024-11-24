#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<LL> A(n + 1), F(n + 2);
    rep(i ,1, n) cin >> A[i];
    LL s = 0, ans = 0;
    per(i, n, 1) {
        F[i] += F[i + 1];
        s += F[i];
        LL t = A[i] - s;
        if(t <= 0) continue;
        int nw = min(k, i);
        LL op = (t + nw - 1) / nw;
        s += op * nw; ans += op;
        F[i] -= op;
        F[max(0, i - k - 1)] += op;
    }       
    cout << ans << '\n';
    return 0;
}