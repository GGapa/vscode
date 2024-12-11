#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B(n + 1), C(n + 1);
    rep(i ,1 ,n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];

    auto check = [&](int x) {
        assert(0 <= x && x <= B[1]);
        auto C = B; C[1] -= x;

        rep(i, 2, n) {
            int sum = C[i - 1] + C[i] - A[i], t = A[i];
            if(sum < 0) return -1;
            t = max(0, t - C[i - 1]);
            C[i - 1] = 0;
            C[i] -= t;
            if(C[i] < 0) return -1;
        }
        return (C[n] + C[1] - (A[1] - x) >= 0 ? 1 : 0);
    };
    

    int l = 0, r = B[1], res = 0;
    while(l <= r) {
        int mid = l + r >> 1;
        int t = check(mid);
        if(t == 1) return cout << "YES\n", void();
        else if(t == 0) l = mid + 1;
        else r = mid - 1;
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}