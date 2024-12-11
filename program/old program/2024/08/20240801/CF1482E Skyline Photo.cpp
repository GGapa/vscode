#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int INF = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> h(n + 1), b(n + 1);
    rep(i, 1, n) cin >> h[i];
    rep(i, 1, n) cin >> b[i];
    vector<LL> F(n + 1), mx(n + 1);
    vector<int> stk;
    rep(i, 1, n) {
        LL &t = mx[i] = (stk.empty() ? -INF : F[stk.back()]);
        while(!stk.empty() && h[stk.back()] > h[i]) t = max(t, mx[stk.back()]), stk.pop_back();
        F[i] = max(stk.empty() ? b[i] : F[stk.back()], t + b[i]);
        stk.push_back(i);
    }
    rep(i, 1, n) cout << F[i] << " \n"[i == n];
    cout << F[n] << '\n';
    return 0;
}