//Subarray Divisibility gym102961ZC
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    map<int, int> mp;
    mp[0] = 1;
    int ans = 0, s = 0;
    for(int i = 1, x ; i<= n; i++) {
        cin >> x; s += x;
        ans += mp[(s % n + n) % n]++;
    }
    cout << ans << '\n';
    return 0;
}