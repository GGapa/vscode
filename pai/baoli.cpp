#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> L(n + 1), R(n + 1);
    rep(i, 1, n) cin >> L[i] >> R[i];
    int q; cin >> q;
    for(int x; q--; ) {
        cin >> x;
        rep(i, 1, n) if(L[i] <= x && x <= R[i]) x++;
        cout << x << '\n';
    }
    return 0;
}