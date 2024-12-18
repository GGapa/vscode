#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string S; cin >> S; 
    int tp = (1 << n) - 1;
    vector<vector<int>> G(tp + 1); vector<int> F(tp + 1, 0);
    auto check = [&](int s) {
        string t;
        rep(i, 0, n - 1) if(s >> i & 1) t += S[i];
        return t == string(t.rbegin(), t.rend());
    };
    F[0] = 0;
    rep(s, 0, tp) {
        for(int s1 = s, j = -1; j; j = s1, s1 = (s1 - 1) & s) {
            int s2 = s1 ^ s;
            if(check(s2) || F[s1] + 1 <= F[s])  continue;
            G[s] = G[s1]; G[s].emplace_back(s2); F[s] = F[s1] + 1;
        }
    }
    if(G[tp].empty()) cout << "Shuiniao\n";
    else {
        cout << "Huoyu\n";
        cout << F[tp] << '\n';
        for(auto s : G[tp]) {
            cout << __builtin_popcount(s) << " ";
            rep(i, 0, n - 1) if(s >> i & 1) {
                cout << i + 1 << " ";
            }
            cout << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int qwq; cin >> qwq;
    int T; cin >> T;
    while(T--) solve();
    return 0;
}