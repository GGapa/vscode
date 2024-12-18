#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i ,1, n) cin >> A[i];
    bool tag=  1;
    rep(i, 1, n) if(A[i] != i) tag= 0;
    if(tag) return cout << 0 << '\n', void();
    if(A[1] == n && A[n] == 1) return cout << 3 << '\n', void();
    tag = 0;
    for(int i = 1, mx = A[1]; i <= n; i++) {
        mx = max(mx, A[i]);
        if(mx <= i && A[i] == i) 
            {tag = 1; break;}
    }
    if(A[1] == 1 || A[n] == n || tag) return cout << 1 << '\n', void();
    cout << 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}