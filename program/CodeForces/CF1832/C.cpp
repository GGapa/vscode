#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(1), vis(n + 1), B(n + 1);
    rep(i, 1, n) cin >> B[i];
    for(int i = 1, j = 1; i <= n; )  {
        A.emplace_back(B[i]);
        while(j <= n && B[i] == B[j]) j++;
        i = j;
    }
    n = A.size() - 1;
    int ans = 2;
    rep(i, 2, n - 1) if((A[i - 1] <= A[i]) != (A[i] <= A[i + 1])) {
        ans++;
    }
    cout << min(n, ans) << '\n'; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}