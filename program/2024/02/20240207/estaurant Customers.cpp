//estaurant Customers
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> a;
    for(int i = 1, l, r; i <= n; i++) {
        cin >> l >> r;
        a.push_back({l, 1}); a.push_back({r, -1});
    }
    sort(a.begin(), a.end());
    int t = 0, ans = 0;;
    for(auto i : a) {
        t += i.second; ans = max(ans , t);
    }
    cout << ans << '\n';
    return 0;
}