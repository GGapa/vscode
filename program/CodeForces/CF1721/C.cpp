#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1), mn(n + 1), mx(n + 1);
    rep(i ,1, n) cin >> A[i];
    rep(i ,1, n) cin >> B[i] ;
    per(i, n, 1) {
        int it = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
        mn[i] = B[it] - A[i], mx[i] = *B.rbegin() - A[i];
        if(it == i) while((int)B.size() - 1 >= i) B.pop_back();
    }
    rep(i, 1, n) cout << mn[i] << " \n"[i == n];
    rep(i, 1, n) cout << mx[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}