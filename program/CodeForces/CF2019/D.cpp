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
    vector<int> l(n + 1, n + 1), r(n + 1, -1);
    rep(i, 1, n) l[A[i]] = min(l[A[i]], i), r[A[i]] = max(r[A[i]], i);
    int L = n + 1, R = -1;
    vector<int> F(n + 4);
    rep(i, 1, n) {
        L = min(L, l[i]); R = max(R, r[i]);
        if(R - L  + 1<= i) {
            int ll = max(1, R - i + 1);
            int rr = min(n, L + i - 1);
            F[ll]++; F[rr + 1]--;
        }
    }
    int cnt = 0;
    rep(i, 1, n) F[i] += F[i - 1], cnt += (F[i] == n);
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}