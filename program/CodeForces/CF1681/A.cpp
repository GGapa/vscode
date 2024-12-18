#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    int m; cin >> m;
    vector<int> B(m + 1);
    rep(i, 1, m) cin >> B[i];
    sort(A.begin(), A.end()); sort(B.begin(), B.end()); 
    if(A[n] >= B[m]) cout << "Alice\n";
    else cout << "Bob\n";
    if(B[m] >= A[n]) cout << "Bob\n";
    else cout << "Alice\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}