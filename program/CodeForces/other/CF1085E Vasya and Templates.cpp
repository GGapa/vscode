#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> k;
    string s, a, b; cin >> s >> a >> b;
    if(a > b) swap(a, b);
    n = s.size(); s = " " + s, a = " " + a, b = " " + b;
    vector<int> p(k + 1, -1), q(k + 1, -1);
    auto out = [&]() {
        string ans;
        for(int i = 0, j = 0; i < k; i++) {
            if (p[i] >= 0) ans += 'a' + p[i];
            else {
                while (q[j] >= 0) j++;
                ans += 'a' + j++;
            }
        }
        cout << "YES\n";
        cout << ans << '\n';
    };
    auto check = [&](int x, int y) {
        if(p[x] >= 0 && p[x] != y) return false;
        if(q[y] >= 0 && q[y] != x) return false;
        p[x] = y; q[y] = x; return true;
    };
    bool tag = false;
    rep(i, 1, n) {
        rep(c, a[i] - 'a' + 1, (tag ? k - 1 : b[i] - 'a' - 1)) if(check(s[i] - 'a', c)) return out(), void();
        if(!check(s[i] - 'a', a[i] - 'a')) break;
        if(a[i] != b[i]) tag = true;
        if(i == n) return out(), void();
    }
    tag = false;
    p.assign(k + 1, -1); q = p;
    rep(i, 1, n) {
        rep(c, (tag ? 0 : a[i] - 'a' + 1), b[i] - 'a' - 1) if(check(s[i] - 'a', c)) return out(), void();
        if(!check(s[i] - 'a', b[i] - 'a')) break;
        if(a[i] != b[i]) tag = true;
        if(i == n) return out(), void();
    }
    cout << "NO\n";
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
5
acdbccc
bdaedae
eecdaca
*/