#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const double eps = 1e-8;

void solve() {
    string s, x, y; cin >> s >> x >> y;
    int c1, c2, c3, c4; c1 = c2 = c3 = c4 = 0;
    for(auto c : x) c1 += (c == '0'), c2 += (c == '1');
    for(auto c : y) c3 += (c == '0'), c4 += (c == '1');
    int n = s.size() ;
    int t1 = c1 - c3, t2 = c4 - c2;
    if(t1 == 0) return cout << "Yes\n", void();
    if(t2 == 0) return cout << "No\n", void();
    double r1 = 1.0 * t2 / t1; int r2 = t2 / t1;
    if(r1 < 0) return cout << "No\n", void();
    set<string> st;
    if(r2 == 0) {
        int gd = __gcd(abs(t1), abs(t2));
        t2 = abs(t2) / gd;
        if(n % t2 != 0) return cout << "No\n", void();
        int le = n / t2;
        for(int i = 0; i <= n - le; i += le) {
            string t;
            for(int j = 0; j < le; j++) t += s[j + i];
            if(st.insert(t).second && i != 0) return cout << "No\n", void();
        }
        return cout << "Yes\n", void();
    }
    if(abs(r1 - r2) > eps || n % r2 != 0) return cout << "No\n", void();
    int le = n / abs(r2);
    for(int i = 0; i <= n - le; i += le) {
        string t;
        for(int j = 0; j < le; j++) t += s[j + i];
        if(st.insert(t).second && i != 0) return cout << "No\n", void();
    }
    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}