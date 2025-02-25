#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string t, s; cin >> t; 
    int n = s.size(), m = t.size();
    t = " " + t; s = t + "#" + s;
    vector<int> nxt(m + 2 + n);
    for(int i = 2, j = 0; i <= m + n + 1; i++) {
        while(j && s[i] != s[j + 1]) j = nxt[j];
        j += (s[i] == s[j + 1]);
        nxt[i] = j;
    }
    rep(i, 1, m) cout << nxt[i] << " \n"[i == m];
    return 0;
}