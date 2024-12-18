#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1);
    ll sum = 0;
    int l = 1e9, r = 0;
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i], sum += abs(A[i] - B[i]);
    rep(i ,1, n) if(A[i] > B[i]) swap(A[i], B[i]);
    rep(i ,1, n) r = max(r, A[i]), l = min(l, B[i]);
    cout << sum + max(r - l, 0) * 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}