#pragma GCC optimize(3)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    unordered_map<int, vector<int>> mp;
    int n, q; cin >> n >> q;
    string s; cin >> s; s = " " + s;
    vector<int> S(n + 1) ;
    rep(i, 1, n) S[i] = S[i - 1] + (i & 1 ? 1 : -1) * (s[i] == '+' ? 1 : -1), mp[S[i]].emplace_back(i);
    for(auto &p : mp) sort(p.second.begin(), p.second.end());
    for(int l, r; q--; ) {
        cin >> l >> r;
        int t = (S[r] - S[l - 1]);
        if(t == 0) {
            cout << 0 << '\n';
            continue;
        }
        else if(t & 1) cout << 1 << '\n';
        else cout << 2 << '\n' << l << " ", l++;
        t = S[r] - S[l - 1];
        t = S[l - 1] + (t + (t > 0 ? 1 : -1)) / 2;
        cout << *lower_bound(mp[t].begin(), mp[t].end(), l) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
+--++---++-++-
*/