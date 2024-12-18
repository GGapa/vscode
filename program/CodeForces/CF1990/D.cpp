//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i ,1, n) cin >> A[i];
    const int INF = 1e9;
    vector<int> G(n + 1, INF), F(n + 1, INF);
    F[0] = 0;
    for(int i = 1, x; i <= n; i++) {
        x = A[i];
        int &f = F[i];
        F[i] = min(F[i - 1] + (x > 0), F[i]);
        if(x <= 2) f = min(G[i] = F[i - 1] + 1, f), F[i] = min(G[i - 1], f);
        if(i >= 2 && A[i] <= 4 && A[i - 1] <= 4) G[i] = min(G[i - 2] + 2, G[i]);
    }
    rep(i, 1, n) cout << F[i] << " \n"[i == n];
    rep(i, 1, n) cout << G[i] << " \n"[i == n];
    cout << F[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

