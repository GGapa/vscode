#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LL x; cin >> x;
    if(x > 1ll * (n - 2) * (n - 2 + 1) / 2) return cout << -1 << '\n', 0;
    vector<int> id(n - 2);
    iota(id.begin(), id.end(), 1);
    vector<int> in, out;
    LL now = 0;
    for(auto i : id) {
        if(now + (n - 1 - i) <= x) now += (n - 1 - i), in.emplace_back(i);
        else out.emplace_back(i);
    }
    cout << n << " ";
    for(auto i : in) cout << i << " ";
    cout << n - 1 << " ";
    reverse(out.begin(), out.end());
    for(auto i : out) cout << i << " ";

    return 0;
}