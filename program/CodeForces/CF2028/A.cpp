#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s; s = " " + s;
    int dx, dy; dx = dy = 0;
    for(int i = 1, cnt = 0; cnt <= 1000; i++, cnt++) {
        if(s[i] == 'N') dy++;
        else if(s[i] == 'E') dx++;
        else if(s[i] == 'W') dx--;
        else dy--;
        if(i == n) i = 0;
        if(dx == a && dy == b) return cout << "YES\n", void();
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