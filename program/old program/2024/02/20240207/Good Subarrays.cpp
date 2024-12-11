//Good Subarrays CF1398C
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

void solve() { 
    int n; cin >> n;
    vector<int> sum(n + 1);
    map<int ,int> mp;
    mp[0] = 1;
    int ans = 0;
    rep(i, 1, n) {
        char c; cin >> c;
        sum[i] += sum[i - 1] + c - '0';
        ans += mp[sum[i] - i]++;
    }
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