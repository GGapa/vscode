#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n) ;
    int x; cin >> x;
    rep(i, 1, n - 1) cin >> A[i];
    sort(A.begin() + 1, A.end());
    rep(i, 1, n - 1) {
        if(A[i] > x) x = (A[i] + x) -  ((A[i] + x)) / 2;
    }
    cout << x << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}