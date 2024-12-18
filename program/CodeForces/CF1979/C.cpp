//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> A(n + 1);
    rep(i, 1, n) cin >> A[i][0], A[i][1] = i;
    sort(A.begin() + 1, A.end());
    vector<int> ans(n + 1, 1);
    int sum = n;
    auto calc = [&](int i) {
        int del = sum - ans[A[i][1]] * A[i][0];
        if(del <= 0) return ;
        int t = del / (A[i][0] - 1) + 1;
        // cout << t << '\n';
        sum += t;
        ans[A[i][1]] += t;
    };
    rep(i, 1, n) {
        calc(i);
        per(j, i - 1, 1)  
            calc(j);
        rep(i, 1, n) cout <<  ans[A[i][1]] << " \n"[i == n];
        // if(ans[A[i][1]] * A[i][0] <= sum) return cout << "-1\n", void();
    }
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}