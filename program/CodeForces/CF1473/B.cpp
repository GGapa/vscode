#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    string a, b; cin >> a >> b;
    if(a.size() > b.size()) swap(a, b);
    int n = a.size(), m = b.size();
    int lcm = (n * m) / (int)__gcd(m, n);
    string na, nb; na = nb = "";
    rep(i, 1, lcm / n) na += a;
    rep(i, 1, lcm / m) nb += b;
    if(na == nb) cout << na << '\n';
    else cout << "-1\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}