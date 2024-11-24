#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size(); 
    a = " " + a, b = " " + b;
    if(a[1] == b[1]) {
        cout << "YES\n";
        return cout << a[1] << "*\n", void();
    }
    if(a[n] == b[m]) {
        cout << "YES\n";
        return cout << "*" << a[n] << '\n', void();
    }
    rep(i, 1, n - 1) rep(j, 1, m - 1) if(a[i] == b[j] && a[i + 1] == b[j + 1]) {
        cout << "YES\n";
        return cout << "*" << a[i] << a[i+1] << "*" << '\n', void();
     }
     cout << "NO\n";
 }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}