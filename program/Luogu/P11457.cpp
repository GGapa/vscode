#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

void solve() {
    int n; cin >> n;
    priority_queue<LL> q;
    vector<AI> A(n + 1);
    rep(i, 1, n) rep(j, 0, 1) cin >> A[i][j];
    rep(i, 1, n) A[i][0] += A[i][1];
    sort(A.begin(), A.end(), [&](const AI& x, const AI& y) {
        return (x[0] == y[0] ? x[1] < y[1] : x[0] < y[0]);
    });

    LL sum = 0, ans = 0; 
    rep(i, 1, n) {
        auto &a = A[i];
        sum += a[1];
        q.emplace(a[1]);
        if(sum <= a[0]) ans++;
        else sum -= q.top(), q.pop();
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
    return 0;
}