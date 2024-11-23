#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int a, b, c, d; cin >> a >> b >> c >> d;
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<int> vis(n + 1);
    using AI = array<int, 3>;
    vector<AI> A, B;
    for(int i = 1, j = 1; i <= n; i++) {
        j = i;
        while(j < n && s[j + 1] != s[j]) j++;
        if(j - i + 1>= 2) {
            if(s[i] == 'A' && s[i] != s[j]) A.push_back({(j - i + 1) / 2, i, j});
            if(s[i] == 'B' && s[i] != s[j]) B.push_back({(j - i + 1) / 2, i, j});
        }
        i = j;
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    for(auto a : A) {
        int i = a[1], j = a[2];
        for(int k = i; k <= j; k += 2) {
            if(s[i] == 'A') {
                if(c == 0) break;
                c--; vis[k] = vis[k + 1] = 1;
                if(c == 0) break;
            }
        }
    }

    for(auto a : B) {
        int i = a[1], j = a[2];
        for(int k = i; k <= j; k += 2) {
            if(s[i] == 'B') {
                if(d == 0) break;
                d--; vis[k] = vis[k + 1] = 1;
                if(d == 0) break;
            }
        }
    }

    rep(i, 1, n - 1) if(s[i] != s[i + 1] && vis[i] == 0 && vis[i + 1] == 0) {
        if(s[i] == 'A' && c) c--, vis[i] = vis[i + 1] = 1;
        if(s[i] == 'B' && d) d--, vis[i] = vis[i + 1] = 1;
    }

    rep(i, 1, n) if(!vis[i]) (s[i] == 'A' ? a-- : b--), vis[i] = 1;
    if(a || b || c || d) return cout << "NO\n", void();
    cout << "YES\n", void();
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
1
1 1 2 3
ABABABBAABAB
*/