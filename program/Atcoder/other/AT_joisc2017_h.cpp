#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;

    vector<int> C(n);
    rep(i, 1, n - 1) cin >> C[i];

    vector<VI> A(n + 1);    
    for(int i = 1; i <= n; i++) {
        int k; cin >> k;
        for(int x; k--; ) cin >> x, A[x].emplace_back(i); 
    }

    auto ok = [&](int x, int l, int r) {
        auto &a = A[C[x]];
        return upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
    };

    vector<int> l(n + 1), r(n + 1);
    rep(i, 1, n) {
        l[i] = r[i] = i;
        while(l[i] > 1 || r[i] < n) {
            if(l[i] > 1 && ok(l[i] - 1, l[i], r[i])) 
                r[i] = max (r[i], r[l[i] - 1]), l[i] = min(l[i], l[l[i] - 1]);
            else if(r[i] < n && ok(r[i], l[i], r[i]))
                r[i]++;
            else break;
        }
    }

    int q; cin >> q;

    for(int x, y; q--; ) {
        cin >> x >> y;
        cout << (l[x] <= y && y <= r[x] ? "YES\n" : "NO\n");
    }

    return 0;
}