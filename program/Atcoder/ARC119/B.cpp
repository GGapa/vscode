#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    string t; cin >> t; t = " " + t;
    vector<int> A, B;
    if(count(s.begin(), s.end(), '1') != count(t.begin(), t.end(), '1') || count(s.begin(), s.end(), '0') != count(t.begin(), t.end(), '0')) return cout << -1 << '\n', 0;
    rep(i, 1, n) if(s[i] == '0') A.emplace_back(i);
    rep(i, 1, n) if(t[i] == '0') B.emplace_back(i);
    int ans = 0;
    for(int i = 0; i < (int)A.size(); i++) if(A[i] != B[i]) ans++;
    cout << ans << '\n';
    return 0;
}