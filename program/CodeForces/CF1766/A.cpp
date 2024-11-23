#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int N = 999999 + 1;

int F[N];

void init() {
    int ans = 0;
    rep(i ,1, N - 1) {
        string s = to_string(i);
        int cnt = 0;
        for(auto c : s) cnt += (c != '0');
        ans += (cnt == 1) ;
        F[i] = ans;
    }
    // cout << ans << '\n';
}

void solve() {
    int n; cin >> n;
    int ans = 0;
    cout << F[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    init();
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}