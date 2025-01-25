#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

template<int siz>
using AI = array<int, siz>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, d; cin >> n >> d;
    vector<AI<2>> F;
    for(int i = 1, a, b; i <= n; i++) {
        cin >> a >> b;
        if(a < d) continue;
        F.push_back({a, b});
    }

    sort(F.begin(), F.end(), [](const auto &x, const auto &y) {
        auto mx = [&](const AI<2> &x) {return max(x[0], x[1]); };
        if(mx(x) == mx(y)) return x[0] < y[0];
        else return mx(x) < mx(y);
    });

    int ans = 0;
    for(auto a : F) {
        if(d <= a[0]) ans++, d = max(d, a[1]);
    }
    cout << ans << '\n';
    return 0;
}