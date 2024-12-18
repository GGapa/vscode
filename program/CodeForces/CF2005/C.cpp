#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

string s = "narek";

void solve() {
    int n, m; cin >> n >> m;
    vector<int> F(7, -1e9);
    F[0] = 0;
    rep(i, 1, n) {
        string t; cin >> t; t = " " + t;
        vector<int> G = F;
        rep(tt, 0, 4) {
            int it = tt, cnt = 0, a5 = 0;
            rep(j, 1, m) {
                if(s[it] == t[j]) it++;
                if(s.find(t[j]) != string::npos) cnt++;
                if(it == 5) it = 0, a5++; 
            }
            G[it] = max(F[tt] + a5 * 10 - cnt, G[it]);
        } 
        F = G;
    }
    cout << *max_element(F.begin(), F.end()) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
1
5 5
ppppp
aasaa
bbbbb
ccccc
*/