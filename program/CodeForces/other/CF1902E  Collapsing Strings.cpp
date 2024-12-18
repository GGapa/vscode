#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
using UI = unordered_map<int, unordered_map<char, int>>;
UI T, cnt;
int idx = 0;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    auto add = [&](const string &s) {
        int t = 0;
        for(auto c : s) {
            if(!T[t][c]) T[t][c] = ++idx;
            cnt[t][c]++;
            t = T[t][c];
        }
    };
    ll ans = 0;
    auto ask = [&](const string &s) {
        int t = 0;
        for(auto c : s) {
            if(!T[t][c]) break;
            ans -= cnt[t][c] * 2;
            t = T[t][c];
        }
    };
    vector<string> s(n + 1);
    rep(i ,1, n) cin >> s[i], ans += 2 * n * s[i].size(), add(s[i]);
    rep(i, 1, n) ask(string(s[i].rbegin(), s[i].rend()));
    cout << ans << '\n';
    return 0; 
}