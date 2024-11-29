#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e6 + 5;

int nxt[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s; t = " " + t;
    for(int i = 2, j = 0; i <= m; i++) {
        while(j && t[i] != t[j + 1]) j = nxt[j];
        if(t[i] == t[j + 1]) j++;
        nxt[i] = j; 
    }
    for(int i = 1, j = 0; i <= n; i++) {
        while(j && s[i] != t[j + 1]) j = nxt[j];
        if(s[i] == t[j + 1]) j++;
        if(j == m) cout << i - m + 1 << '\n', j = nxt[j];
    }
    rep(i, 1, m) cout << nxt[i] << " \n"[i == n]; 
    return 0;
}