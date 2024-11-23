#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;

    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    int sum = 0, tag = 0;
    for(int i = 1, t = 1; i <= n; i++, t *= -1) sum += A[i] * t;
    if(sum & 1) return cout << -1 << '\n', void();
    sum = 0;
    vector<pair<int, int>> ans;
    vector<int> vis(n + 1);
    int lt = 1;
    rep(i, 1, n) {
        tag--;
        if(abs(sum + A[i]) > abs(sum - A[i]) && tag <= 0) {
            tag = 2;
            sum = sum - A[i];
            vis[i - 1] = 1;
        }
        else {
            sum += A[i];
        }
    }
    rep(i, 1, n) {
        if(vis[i] == 0) ans.emplace_back(i, i);
        else ans.emplace_back(i, i + 1), i++;
    }
    cout << ans.size() << '\n';
    for(auto a : ans) cout << a.first << " " << a.second << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}