#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define CSP2024 GG BUT I WILL WIN NOIP2024
using namespace std;
using LL = long long;
using VI = vector<int>;
constexpr int INF = 1e9 + 7;


void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n - 1) {
        if(A[i] != i) {
            if(abs(A[i + 1] - A[i]) != 1) return cout << "NO\n", void();
            else swap(A[i], A[i + 1]);
        }
    } 
    rep(i, 1, n) if(A[i] != i) return cout << "NO\n", void();
    cout << "YES\n", void();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}