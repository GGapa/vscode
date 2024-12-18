#include <bits/stdc++.h>
#define int long long
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    map<int, int> mp;
    for(int i = 1, x; i <= n; i++) cin >> x, mp[x]++;
    int lst = 0, rem = n, ans = 0, sum = 0;
    for(auto p : mp) {
        int num = p.second, val = p.first;
        sum += (val - lst) * rem;
        if(sum >= k) return cout << k + ans << '\n', void();
        lst = val; rem -= num; ans += num;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}