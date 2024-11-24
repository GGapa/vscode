#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long 
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> A(n + 1);
    rep(i ,1, n) cin >> A[i];
    sort(A.begin() + 1, A.end(), greater<>()) ;
    vector<int> S(n + 1);
    rep(i, 1, n) S[i] += S[i - 1] + A[i];
    for(int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        cout << S[x] - S[x - y] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1; 
    // cin >> T;
    while(T--) solve();
    return 0;
}