#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto& i : a) cin >> i;
    for(auto& i : b) cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for(int i = 0; i < n; i++) 
        ans += max(abs(a[i] - b[m - i - 1]), abs(a[i] - b[n - i - 1]));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
// 不开 long long 见祖宗
// 对于绝对值问题可以考虑贪心