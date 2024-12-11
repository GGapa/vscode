// Color Length
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int INF = 1e9;

void solve() {
    string a, b; cin >> a >> b;
    int n = a.size(), m = b.size();
    vector<int> sa(26, INF), ea(26, -1), sb = sa, eb = ea;
    rep(i, 0, n - 1) {
        int c = a[i] - 'A';
        sa[c] = min(sa[c], i); ea[c] = i;
    }
    rep(i, 0, m - 1) {
        int c = b[i] - 'A';
        sb[c] = min(sb[c], i); eb[c] = i;
    }
    using VI = vector<int>;
    vector<VI> F(n + 1, VI(m + 1, INF)), C(n + 1, VI(m + 1));
    F[0][0] = 0;
    rep(i, 0, n) rep(j, 0, m) if(i + j) {
        int &f = F[i][j], &c = C[i][j];
        if(i) {
            int i1 = i - 1, aa = a[i1] - 'A', c1 = C[i1][j];
            f = min(f, F[i1][j] + c1);
            c = c1 + (sa[aa] == i1 && sb[aa] >= j) - (ea[aa] == i1 && eb[aa] < j);
        }
        if(j) {
            int j1 = j - 1, bb = b[j1] - 'A', c1 = C[i][j1];
            f = min(f, F[i][j1] + c1);
            c = c1 + (sb[bb] == j1 && sa[bb] >= i) - (eb[bb] == j1 && ea[bb] < i);
        }
    }
    cout << F[n][m] << '\n';
}


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}