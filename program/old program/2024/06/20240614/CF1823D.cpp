//D. Unique Palindromes
//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> x(k + 2), c(k + 2);
    rep(i, 1, k) cin >> x[i];
    rep(i, 1, k) cin >> c[i];
    adjacent_difference(x.begin() , x.begin() + k + 1, x.begin());
    adjacent_difference(c.begin() , c.begin() + k + 1, c.begin());
    rep(i, 1, k) if(x[i] < c[i]) return false;
    string ans = "abc";
    int ad = 0;
    rep(i, 1, k) {
        int t = x[i] - c[i];  
        while(t--) ans += 'a' + ad, (++ad == 3 && (ad = 0));
        t = c[i];
        if(i == 1) t -= 3;
        ans += string(t, 'c' + i);
    } 
    cout << "YES\n" << ans << '\n';
    return true;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) if(!solve()) cout << "NO\n";
    return 0;
}