#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    string s; cin >> s; s = " " + s;
    unordered_map<char, vector<int>> cnt;
    cnt['A'] = cnt['T'] =cnt['G'] = cnt['C'] = vector<int>(n + 1);
    rep(i, 1, n) {
        cnt[s[i]][i]++;
        for(auto c : {'A', 'T', 'G', 'C'}) cnt[c][i] += cnt[c][i - 1];
    }
    int ans = 0;
    rep(i, 1, n) rep(j, i, n) if(cnt['A'][j] - cnt['A'][i - 1] == cnt['T'][j] - cnt['T'][i - 1] && cnt['G'][j] - cnt['G'][i - 1] == cnt['C'][j] - cnt['C'][i - 1]) ans++;
    cout << ans << '\n';
    return 0;
}