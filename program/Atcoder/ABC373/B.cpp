#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int ans = 0, st;
    rep(i, 0, 25) if(s[i] == 'A') st = i;
    rep(i, 1, 25) 
        rep(j, 0, 25) if(s[j] == 'A' + i) 
            ans += abs(st - j), st = j;
    cout << ans << '\n';
    return 0;
}