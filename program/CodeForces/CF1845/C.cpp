#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string  s; cin >> s;
    int m; cin >> m;
    string l; cin >> l;
    string r; cin >> r;
    int n = s.size();  
    s = " " + s;
    l = " " + l; r = " " + r;
    vector<VI> AA(11);
    rep(i ,1, n) AA[s[i] - '0'].emplace_back(i);
    for(int i = 1, lst = 0; i <= m; i++) {
        int tmp = 0;
        rep(j, l[i] - '0', r[i] - '0') {
            auto &A = AA[j];
            auto it = upper_bound(A.begin(), A.end(), lst);
            if(it == A.end()) return cout << "YES\n", void();
            tmp = max(tmp, *it);
        }
        lst = max(lst, tmp);
    }
    cout << "NO\n", void();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}