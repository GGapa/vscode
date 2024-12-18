// Insert or Erase
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<int>  a(n + 1);
    unordered_map<int, int> F, N;
    rep(i, 1, n) cin >> a[i], F[a[i]] = a[i - 1], N[a[i - 1]] = a[i];
    int rt = a[1], ed = a[n];
    N[a[n]] = -1;
    int q; cin >> q;
    for(int i = 1, op, x, y; i <= q; i++) {
        cin >> op >> x;
        if(op == 2) {
            if(rt == x) rt = N[x];
            // if(ed == x) ed = F[x];
            N[F[x]] = N[x];
            F[N[x]] = F[x];
            N[x] = F[x] = 0;
        }
        if(op == 1) {
            cin >> y;
            F[N[x]] = y;
            N[y] = N[x];
            F[y] = x;
            N[x] = y;
        }
    }
    for(; rt != -1; rt = N[rt]) {
        cout << rt << ' ';
    }
    // cout << ed << '\n';
    return 0;
}