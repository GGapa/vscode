#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    priority_queue<int> ql;
    priority_queue<int, VI, greater<int>> qr;
    vector<int> l(n + 1), r(n + 1), len(n + 1);
    rep(i, 1, n) cin >> l[i] >> r[i], len[i] = r[i] - l[i] ;
    ql.push(l[1]), qr.push(l[1]);
    int tl, tr; tl = tr = 0;
    int ans =0;
    rep(i, 2, n) {
        tl -= len[i], tr += len[i - 1];
        int L = ql.top() + tl, R = qr.top() + tr;
        if(l[i] < L) {
            ans += L - l[i];
            ql.pop();
            ql.push(l[i] - tl); ql.push(l[i] - tl);
            qr.push(L - tr);
        }
        else if(l[i] > R) {
            ans += l[i] - R;
            qr.pop();
            qr.push(l[i] - tr); qr.push(l[i] - tr);
            ql.push(R - tl);
        }
        else {
            ql.push(l[i] - tl);
            qr.push(l[i] - tr);
        }
    }
    cout << ans << '\n';
    return 0;
}