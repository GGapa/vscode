#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1);
    rep(i ,1, n) cin >> A[i];
    sort(A.begin() + 1, A.end(), greater<>()) ;
    int c0, c1; c0 = c1 = 0;
    int ans = 0;
    for(int i = 1; i < n; i += 2) {
        int t = min(k, A[i] - A[i + 1]) ;
        k -= t;
        A[i + 1] += t;
    }
    rep(i ,1, n) {
        if(i & 1) c0 += A[i];
        else c1 += A[i];
    }
    cout << c0 - c1 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}