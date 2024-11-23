#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<int> nxt(n + 20) ;
    for(int i = 2, j = 0; i <= n; i++) {
        while(j && s[j + 1] != s[i]) j = nxt[j] ;
        if(s[j + 1] == s[i]) j++;
        nxt[i] = j;
    }
    vector<VI> F(n + 20, VI(28)) ;
    rep(i, 0, n - 1) rep(j, 0, 25) F[i][j] = F[nxt[i]][j], F[i][s[i + 1] - 'a'] = i;
    int q; cin >> q;
    s = s + "                           ";
    while(q--) {
        string t; cin >> t;
        int m = t.size() ;
        rep(i, 0, m - 1) s[n + i + 1] = t[i] ; 
        rep(i, n + 1, n + m ) {
            nxt[i] = 0;
            rep(j, 0, 25) F[i][j] = 0;
        } 
        rep(j, 0, 25) F[n][j] = F[nxt[n]][j];
        F[n][s[n + 1] - 'a'] = n;
        for(int i = n + 1, j = nxt[n]; i <= n + m; i++) {
            if(s[j + 1] != s[i]) j = F[j][s[i]-'a'];
            if(s[j + 1] == s[i]) j++;
            cout << (nxt[i] = j) << " ";
            for(int k = 0; k < 26; k++) F[i][k] = F[j][k]; 
            if(i != n + m) F[i][s[i + 1] - 'a'] = i;
        }
        cout << '\n';
    }
    return 0;
}