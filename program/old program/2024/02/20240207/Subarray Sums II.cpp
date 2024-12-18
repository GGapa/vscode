//Subarray Sums II
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
    int n, x;
    cin >> n >> x;
    map<int, int>mp;
    int s = 0, ans = 0;
    mp[0] = 1;
    rep(i, 1, n) {
        int t; cin >> t;
        s += t; 
        ans += mp[s - x];
        mp[s]++;
    }
    cout << ans << '\n';
    return 0;
}