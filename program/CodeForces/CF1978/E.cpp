//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    a = " " + a, b = " " + b;
    auto c = a, d = b;
    for(int i = 1; i + 2 <= n; i++) if(a[i] == a[i + 2] && a[i] == '0') d[i + 1] = '1';
    for(int i = 1; i + 2 <= n; i++) if(d[i] == d[i + 2] && d[i] == '1') c[i + 1] = '1'; 
    vector<int> S(n + 1);
    rep(i, 1, n) S[i] = S[i - 1] + (c[i] == '1');
    int q; cin >> q;
    int ret = 0;
    auto chk = [&](int i, int j) {
        if(c[i] == '1' && a[i] == '0') ret--;
        if((i < n || j < 0) && (i > 1 || j > 0)) 
            if(c[i - j] == '1' && a[i - j] == '0' && b[i] == '0') ret--;
    };
    for(int o = 1, l, r; o <= q; o++) {
        cin >> l >> r;
        if(r - l + 1 <= 3) {
            ret = 0;
            ret += (a[l] == '1');
            if(l != r) ret += (a[r] == '1');
            if(r - l + 1 == 3) ret += ((c[l + 1] == '1' && b[r] == '1' && b[l] == '1') || a[l + 1] == '1');
            cout << ret << '\n';
            continue;
        }
        ret = S[r] - S[l - 1];
        chk(r, 1); chk(l, -1); 
        cout << ret << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}