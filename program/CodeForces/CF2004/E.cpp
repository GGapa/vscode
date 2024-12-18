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
    int cnt = 0;
    rep(i, 1, n) {
        if(A[i] <= 2) cnt += A[i];
        else cnt += (A[i] % 2) + 1;
    }
    if(cnt % 2) cout << "Bob\n";
    else cout << "Alice\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
对于每一个不是 1 的棋子，Alice 都最少要把他取用两次才行。
考虑有哪些数字可以改变，奇偶性质
*/