// P5020
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> A(n);
    for(auto &a : A) cin >> a;
    sort(A.begin(), A.end());
    int ans = 0;
    vector<int> F(A.back() + 1);
    F[0] = 1;
    for(auto a : A) {
        ans += (F[a] == 0);
        rep(j, a, A.back()) F[j] += F[j - a];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();

    
    return 0;
}