// Tandem Repeats?
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    string s; cin >> s;
    int n = s.size();
    int ans = n;
    for(int len = n / 2; len >= 1; len--) {
        int cnt = 0;
        for(int i = 0; i + len < n; i++) {
            if(s[i] == s[i + len] || s[i] == '?' || s[i + len] == '?') cnt++;
            else cnt = 0;
            if(cnt == len) {
                cout << len * 2 << '\n';
                return ;
            }
        }
    }
    cout << 0 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}