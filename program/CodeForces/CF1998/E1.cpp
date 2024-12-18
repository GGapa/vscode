#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, x; cin >> n >> x;
    vector<int> A(n + 4), S(n + 4);
    set<int> s({0, n +  1});
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n + 1) S[i] = S[i - 1] + A[i];
    vector<int> op(n + 1); iota(op.begin(), op.end(), 0);
    sort(op.begin() + 1, op.end(), [&](const int &x, const int &y) {
        return A[x] > A[y];
    });
    vector<int> F(n + 2);
    rep(c, 1, n) {
        int i = op[c];
        int l = *prev(s.lower_bound(i));
        int r = *s.lower_bound(i);
        int t = S[r - 1] - S[l];
        if(c == 1) F[i] = 1;
        if(t >= A[l]) F[i] |= F[l];
        if(t >= A[r]) F[i] |= F[r];
        s.insert(i);
    }
    cout << accumulate(F.begin(), F.end(), 0) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}