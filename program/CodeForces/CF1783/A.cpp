#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i ,1 ,n) cin >> A[i];
    sort(A.begin() + 1, A.end()) ;
    if(A[1] == A[n]) return cout << "NO\n", void();
    cout << "YES\n";
    cout << A[n] << " " << A[1] << ' ';
    rep(i, 2, n - 1) cout << A[i] << " \n"[i == n - 1];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}