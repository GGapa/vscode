//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    string s; cin >> s; s = " " + s;
    vector<int> pre(n + 2);
    rep(i, 1, n) pre[i] = pre[i - 1] + (s[i] - '0');
    vector<int> F(n + 2);
    F[n + 1] = 1; 
    pre[n + 1] = pre[n];
    per(i, n, 1) {
        int j = min(n + 1, i + k);
        F[i] = F[j] && (pre[j - 1] - pre[i - 1] == j - i || pre[j - 1] - pre[i - 1] == 0) && (j == n + 1 || s[i] != s[j]);
    }
    rep(i, 1, n) {
        if(s[i] !=  (((i - 1) / k % 2) ^ s[1])) break;
        if(F[i + 1] && (i == n || s[i + 1] == ((n - 1) / k % 2 ^ s[1]))) return cout << i << "\n", void();
    }
    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T ;
        while(T--) solve();
    return 0;
}

