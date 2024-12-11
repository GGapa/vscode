#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<LL> c(n + 3), t(n + 3) ;
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n) cin >> t[i];
    if(c[1] != t[1] || c[n] != t[n]) return cout << "No\n", 0;
    vector<LL> A(n + 2), B(n + 2) ;
    rep(i, 1, n + 1) A[i] = c[i] - c[i - 1];
    rep(i, 1, n + 1) B[i] = t[i] - t[i - 1];
    sort(A.begin() + 1, A.end()); sort(B.begin() + 1, B.end()) ;
    cout << (A == B ? "Yes\n" : "No\n");
    return 0;
}
/*
C0 C1 C2 C3 C4
C0 C1 C3 + C1 - C2 C3 C4
C0 C1 C3 + C1 - C2 C4 + C1 - C2 C4
每次操作都传递了 C1 - C2
C0 C3 + C0 - C2 C3 + C1 - C2 C4 + C1 - C2 C4
传递了 C3 - C2 每次操作会传递差，考虑消去相同的，得到方差。
C3 - C2 C1 - C0 
*/
