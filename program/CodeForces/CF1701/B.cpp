#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    cout << 2 << '\n' ;
    vector<int> cnt(n + 1);
    for(int i = 1; i <= n; i++) if(!cnt[i]) {
        for(int j = i; j <= n && !cnt[j]; j *= 2) {
            cout << j << " ";
            cnt[j] = 1;
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}