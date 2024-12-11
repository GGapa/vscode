// Building Teams
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<array<ll, 2>, vector<array<ll, 2>>, greater<array<ll, 2>>> q;
    for(int i = 1, u, v; i <= n; i++) 
        cin >> u >> v, q.push({1ll * u, 1ll * v});
    int ans = 0;
    while(!q.empty()) {
        ll x = q.top()[0], y = q.top()[1];
        q.pop();
        while(!q.empty() && q.top()[0] == x) y += q.top()[1], q.pop();
        if(y >= 2) q.push({x * 2, y / 2});
        ans += y % 2;
    }
    cout << ans << '\n';
    return 0;
}