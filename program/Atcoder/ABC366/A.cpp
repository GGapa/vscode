#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, t, a; cin >> n >> t >> a;
    if(min(t, a) + (n - t - a) > max(t, a)) return cout << "No\n", 0;
    else cout << "Yes\n";
    return 0;
}