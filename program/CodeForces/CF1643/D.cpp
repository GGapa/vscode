#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> B(n + 2), A(2 * n + 2, 1), S = A, P = A;
    vector<int> ix(n + 1), in(n + 1);
    rep(i, 1, n) cin >> B[i], A[B[i]] = 0;
    int ans = n + 1;
    int lt ;
    rep(i, 1, n) {
        if(B[i] == i) ans--, lt = i;
        else break;
    }
    per(i, n, lt + 1) {
        if(B[i] == n * 2 - (n - i )) ans--;
        else break;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}