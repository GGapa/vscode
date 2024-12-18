#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    string s; cin >> s; s = " " + s;
    vector<pair<int, int>> A;
    for(int i = 1, l, r; i <= m; i++) 
        cin >> l >> r, A.emplace_back(l, r);
    A.erase(unique(A.begin(), A.end()), A.end());
    vector<int> pre(n + 2), suf(n + 2, n + 1);
    rep(i, 1, n) pre[i] = (s[i] == '0' ? i : pre[i - 1]);
    per(i, n, 1) suf[i] = (s[i] == '1' ? i : suf[i + 1]);
    map<pair<int, int>, bool> mp;
    for(auto i : A) {
        int r = pre[i.second], l = suf[i.first]; 
        if(l > r) {
            mp[{-1, -1}] = 1;
            continue;
        }
        mp[{l, r}] = 1;
    }
    cout << mp.size() << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}