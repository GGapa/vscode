//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s;cin >> s;
    vector<int> F(26);
    for(auto c : s) {
        int sum = 0;
        for(auto x : F) (sum += x) %= mod;
        F[c - 'a'] = (sum + 1) % mod;
    }
    int ans = 0;
    for(auto x : F) (ans += x) %= mod;
    cout << ans  << '\n';
    return 0;
}