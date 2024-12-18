#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    int l = 1, r = n ;
    while(s[l] == s[r] && l < r) l++, r--;
    while(s[l] == s[l + 1] && l < r) l += 2;
    while(s[r] == s[r - 1] && l < r) r -= 2;
    if(l > r) return cout << "Draw\n", void();
    else cout << "Alice\n" ;
} 

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}