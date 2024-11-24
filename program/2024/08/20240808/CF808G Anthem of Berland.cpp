#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s, t = " " + t;
    auto check = [&](int x) {
        for(int i = 1; i <= m; i++) if(s[x - i + 1] != t[m - i + 1] && s[x - i + 1] != '?') 
            return false;
        return true;
    };
    vector<int> nxt(m + 1);
    for(int i = 2, j = 0; i <= m; i++) {
        while(j && t[i] != t[j + 1]) j = nxt[j];
        j += (t[i] == t[j + 1]);
        nxt[i] = j;
    }
    vector<int> F(n + 1), G(n + 1);
    rep(i, 1, n) {
        F[i] = F[i - 1];
        if(!check(i)) continue;
        G[i] = F[i - m] + 1;
        for(int j = nxt[m]; j; j = nxt[j]) G[i] = max(G[i], G[i - (m - j)] + 1);
        F[i] = max(F[i], G[i]);
    }
    cout << F[n] << '\n';
    return 0;
}