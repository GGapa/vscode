#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s, ans; cin >> s;
    bool flag = true;
    for(auto c : s) {
        if(c == '|') flag ^= 1;
        else if(flag) ans += c;
    }
    cout << ans << '\n';
    return 0;
}
