#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> ti(n + 2), to(n + 2);
    rep(i, 1, n) cin >> ti[i] >> to[i];
    int lt = 0, tg = 0, ans = 0, st = 0;
    ti[n + 1] = 1e10;
    rep(i, 1, n) {
        if(abs(tg - st) <= ti[i] - ti[lt]) {  // 情况1，当前机器人已经到达了目标地点。
            st = tg;
            tg = to[i];
            lt = i;
            if(i == n || ti[i + 1] - ti[i] >= abs(tg - st)) ans++;
            continue;
        }
         if((st <= to[i] && to[i] <= tg && ti[i] - ti[lt] <= to[i] - st && ti[i + 1] - ti[lt] >= to[i] - st)
           || (st >= to[i] && to[i] >= tg && ti[i] - ti[lt] <= st - to[i]  && ti[i + 1] - ti[lt] >= st - to[i])) ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}