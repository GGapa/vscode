#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> h(n + 1) ;
    LL ans = 1e18;
    auto work = [&](auto h) {
        vector<LL> s(n + 1);
        rep(i, 1, n) s[i] = s[i - 1] + h[i];
        rep(i, 1, n) h[i] -= i - 1;
        vector<LL> s1(n + 1);
        rep(i, 1, n) s1[i] = s1[i - 1] + h[i];
        vector<LL> ans(n + 1);
        deque<int> q;
        int p = 0; LL sum = 0;
        rep(i, 1, n) {
            while(!q.empty() && h[i] < h[q.back()]) {
                int x = q.back(); q.pop_back();
                if(q.empty()) sum -= 1ll * h[x] * (x - p);
                else sum -= 1ll * h[x] * (x - q.back());
            }
            if(q.empty()) sum += 1ll * h[i] * (i - p);
            else sum += 1ll * h[i] * (i - q.back());
            q.push_back(i);
            while(h[q[0]] + p < 0) {
                p++;
                sum -= h[q[0]];
                if(q[0] - 1 < p) q.pop_front();
            }
            ans[i] = (s1[i] - s1[p]) - sum + s[p];
        }
        return ans;
    }; 
    rep(i, 1, n) cin >> h[i];
    auto ans1 = work(h);
    reverse(h.begin() + 1, h.end());
    auto ans2 = work(h);
    reverse(h.begin() + 1, h.end());
    reverse(ans2.begin() + 1, ans2.end( ));
    rep(i, 1, n) ans = min(ans, ans1[i] + ans2[i] + h[i]); 
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}