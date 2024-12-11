#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 1e5 + 10;

int ans[N];


signed main() {
    // freopen("test.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, q; cin >> m >> q;
    vector<pair<int, int>> rg = {{1, m + 1}};
    string s; cin >> s;
    int n = s.size() ;
    s = " " + s + "!";
    rep(i, 1, n) {
        if(s[i] == 'x') {
            char op = s[i + 1];
            int x = 0;
            int j = i + 2;
            for(; isdigit(s[j]); j++) x = x * 10 + (s[j] - '0');
            i = j;
            int l = rg.back().first, r = rg.back().second;
            rg.pop_back();
            if(op == '<') rg.emplace_back(max(l, x), r), rg.emplace_back(l, min(r, x - 1));
            if(op == '>') rg.emplace_back(l, min(r, x)), rg.emplace_back(max(l, x + 1), r);
        }
        else if(s[i] == ':') rg.pop_back();
        else {
            int j = i, x = 0;
            for(; isdigit(s[j]); j++) x = x * 10 + (s[j] - '0');
            i = j;
            // cerr << x << '\n';
            int l = rg.back().first, r = rg.back().second; rg.pop_back();
            rep(i, l, r) ans[i] = x;
        }
    }
    for(int i = 1, x; i <= q; i++) {
        cin >> x;
        cout << ans[min(m + 1, x)] << '\n';
    }
    
    return 0;
}