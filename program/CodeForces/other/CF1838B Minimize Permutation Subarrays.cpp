#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1) ;
    rep(i, 1, n) cin >> A[i] ;
    int a, b, c;
    rep(i, 1, n) {
        if(A[i] == 1) a = i;
        if(A[i] == 2) b = i;
        if(A[i] == n) c = i;
    }
    if(a > b) swap(a, b);
    if(a < c && c < b) cout << a << " " << a << '\n' ; 
    else if(c > b) cout << min(a, b) + 1 << " " << c << '\n';
    else cout << max(a, b) - 1 << " " << c << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}