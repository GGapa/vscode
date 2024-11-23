#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> cnt(x + 2);
    for(int i = 1, t; i <= n; i++) 
        cin >> t, cnt[t]++;
    rep(i, 1, x) {
        cnt[i + 1] += cnt[i] / (i + 1);
        cnt[i] -= cnt[i] / (i + 1) * (i + 1);
    }
    rep(i, 1, x - 1) if(cnt[i]) return cout << "No\n", 0;
    cout << "Yes";
    return 0; 
}