#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    int k; cin >> k;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end());
    int it = A[n];
    per(i, n, 1) {
        while((it - A[i]) / k % 2 && it <= A[n] + k) it++; 
        if((it - A[i]) / k % 2 || it >= A[n] + k) return cout << -1 << '\n', void();
    }
    rep(i, 1, n) if((it - A[i]) / k % 2) return cout << -1 << '\n', void();
    cout << it << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}