#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    int l = 1, r = n * n, t = 1;
    rep(i, 1, n) {
        vector<int> A;
        rep(j, 1, n) {
            A.emplace_back((t ? l++ : r--));
            t ^= 1;
        }
        if((i & 1) == 0) reverse(A.begin(), A.end());
        for(auto a : A) cout << a << " ";
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}