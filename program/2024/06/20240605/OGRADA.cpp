//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    int ans = 0, cnt = 0;
    using pi = pair<int, int>;
    priority_queue<pi, vector<pi>, greater<pi>> q;
    priority_queue<pi> rg;
    for(int i = 1, t; i <= x; i++) cin >> t, q.push({t, i}), ans += t; 
    ans -= q.top().first;
    rg.push({q.top().first, -x}); cnt++;
    int mx = q.top().first, lt = x;
    for(int l = 2, r, t = 0; l <= n; l++) {
        r = l + x - 1;
        if(r <= n) {
            cin >> t; ans += t;
            q.push({t, r});
            while(!q.empty() && q.top().second < l) q.pop();
            rg.push({q.top().first, r});
        }
        while(!rg.empty() && rg.top().second < l) rg.pop();
        if((rg.top().first > mx || lt < l)) {
            cnt ++;
            lt = rg.top().second, mx = rg.top().first;
        }
        ans -= mx;
    }
    cout << ans << '\n' << cnt << '\n';
    return 0; 
}