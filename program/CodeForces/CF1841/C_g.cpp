#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

unordered_map<char, int> val = {{'A', 1}, {'B', 10}, {'C', 100}, {'D', 1000}, {'E', 10000}};


int calc(const string &s) {
    int n = s.size() - 1;
    vector<VI> S(n + 1, VI(6));
    rep(i, 1, n) {
        S[i][s[i] - 'A']++;
        rep(j, 0, 4) S[i][j] += S[i - 1][j];
    }

    int sum = 0;
    rep(i, 1, n) {
        bool tag = 1;
        rep(j, s[i] - 'A' + 1, 4) if(S[n][j] - S[i - 1][j]) tag = false;
        if(tag) sum += val[s[i]];
        else sum -= val[s[i]];
    }
    return sum;
}

void solve() {
    string s; cin >> s; 
    int n = s.size(); s = " " + s;
    vector<int> mx(6, -1), mn(6, -1);
    rep(i, 1, n) mx[s[i] - 'A'] = i;
    per(i, n, 1) mn[s[i] - 'A'] = i;

    int ans = calc(s);
    string t = s;
    rep(i, 0, 4) if(mn[i] != -1)rep(j, s[mn[i]] + 1, 'E') {
        t[mn[i]] = j;
        ans = max(ans, calc(t));
        t = s;
    }

    rep(i, 0, 4) if(mx[i] != -1) per(j, s[mx[i]] - 1, 'A') {
        t[mx[i]] = j;
        ans = max(ans, calc(t));
        t = s;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}