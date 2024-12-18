#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

unordered_map<char, int> val = {{'A', 1}, {'B', 10}, {'C', 100}, {'D', 1000}, {'E', 10000}};

void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    int ans = INT_MIN;
    int sum = 0;
    vector<VI> S(n + 1, VI(6)), F = S;
    rep(i, 1, n) {
        S[i][s[i] - 'A']++;
        rep(j, 0, 4) S[i][j] += S[i - 1][j];
    }

    rep(i, 1, n) {
        bool tag = 1;
        rep(j, s[i] - 'A' + 1, 4) if(S[n][j] - S[i - 1][j]) tag = false;
        if(tag) sum += val[s[i]];
        else sum -= val[s[i]];
        F[i][s[i] - 'A'] += val[s[i]];
        rep(j, 0, 4) F[i][j] += F[i - 1][j];
    }

    rep(i, 1, n) rep(j, 1, 4) F[i][j] += F[i][j - 1];

    ans = sum;

    per(j, 'E', 'A') rep(i, 1, n) {
        bool tg1 = 1, tg2 = 1;
        rep(k, s[i] - 'A' + 1, 4) if(S[n][k] - S[i][k]) tg1 = false;
        rep(k, j + 1 - 'A', 4) if(S[n][k] - S[i][k]) tg2 = false;
        int mx = -1;
        rep(k, 0, 4) if(S[n][k] - S[i][k]) mx = k + 'A';
        ans = max(ans, sum - val[s[i]] * (tg1 ? 1 : -1) + val[j] * (tg2 ? 1 : -1) - 2ll * ((max(j, mx) - 'A' - 1 >= 0 ? F[i - 1][max(j, mx) - 'A' - 1] : 0) - (max((int)s[i], mx) - 'A' - 1 >= 0 ? F[i - 1][max((int)s[i], mx) - 'A' - 1] : 0ll)));
        if(ans == 205220) {
            ans++; ans--;
        }
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