#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1),  B(n + 1);
    vector<array<int, 2>> ans;
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    for(int cnt = 1, tag = 1; tag && cnt <= 1e4; cnt++) {
        tag = 0;
        rep(i, 1, n - 1) if(A[i] > A[i + 1] || B[i] > B[i + 1]) {
            tag = 1;
            swap(A[i], A[i + 1]);
            swap(B[i], B[i + 1]); 
            ans.push_back({i, i + 1}) ;
        }
        if(!tag) {
            cout << ans.size() << '\n';
            for(auto a : ans) cout << a[0] << " " << a[1] << '\n';
            return ;
        }
    }
    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}