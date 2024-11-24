#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    int sz = n % k;
    if(sz == 0) sz += k;
    auto B = A;
    sort(B.begin() + 1, B.end());
    B.erase(unique(B.begin() + 1, B.end()), B.end());
    auto check = [&](int x) {
        vector<int> F(sz + 1);
        rep(i, 1, n) {
            int j = (i - 1) % k;
            if(j >= sz) continue;
            F[j] = max((j == 0 ? 0 : F[j - 1]) + (A[i] >= x), F[j]) ;
        }
        return F[sz - 1] * 2 > sz;
    };
    int l = 1, r = B.size() - 1, ans = 1; 
    while(l <= r) {
        int mid = l + r >> 1;
        if(check(B[mid])) l = mid + 1, ans = mid;
        else r = mid - 1;
    }
    cout << B[ans] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}