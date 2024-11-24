#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

string s = "aeiou";

void solve() {
    int n; cin >> n;
    int x = n / 5, ex = n % 5;
    rep(i, 0, 4) for(int j = 0; j < x + (i < ex); j++) cout << s[i];
    cout << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}