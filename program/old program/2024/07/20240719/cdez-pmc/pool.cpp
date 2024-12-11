#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // freopen("pool.in", "r", stdin);
    // freopen("pool.out", "w", stdout);
    int n; cin >> n;
    vector<array<ll, 2>> A(1), rec(n + 1);
    A[0] = {-1, -1};
    for(int i = 1, x, y; i <= n; i++) {
        cin >> x >> y;
        A.push_back({x, y});
        rec[i] = {x, y};
    }
    int k; cin >> k;
    int m = n;
    vector<int> stk;
    vector<ll> pre(m + 1), suf(m + 1);
    rep(i ,1, m) {
        while(!stk.empty() && A[stk.back()][1] >= A[i][1]) stk.pop_back();
        if(!stk.empty())pre[i] = pre[stk.back()] + (A[i][0] - A[stk.back()][0]) * A[i][1];
        stk.push_back(i);
    }
    vector<int>(0).swap(stk);
    per(i, m, 1) {
        while(!stk.empty() && A[stk.back()][1] >= A[i][1]) stk.pop_back();
        if(!stk.empty())suf[i] = suf[stk.back()] + (A[stk.back()][0] - A[i][0]) * A[i][1];
        stk.push_back(i);
    }
    ll ans = 0;
    rep(i ,1, m) ans = max(ans, pre[i - 1] + suf[i]);
    cout << ans << '\n';
    return 0;
}