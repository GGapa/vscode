// Color Length
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int INF = 1e9;

void solve() {
    string A, B; cin >> A >> B;
    int n = A.length(), m = B.length();
    vector<int> sa(26, INF), ea(26, -1), sb = sa, eb = ea;
    rep(i, 0, n - 1) {
        int c = A[i] - 'A';
        sa[c] = min(sa[c], i); ea[c] = i;
    }
    rep(i, 0, m - 1) {
        int c = B[i] - 'A';
        sb[c] = min(sb[c], i); eb[c] = i;
    }
    using VI = vector<int> ;
    vector<VI> F(n + 1, VI(m + 1, INF)), C(n + 1, VI(m + 1));
    F[0][0] = 0;
    rep(i, 0, n) rep(j, 0, m) {
        int &f = F[i][j];
        if(i) {
            int i1 = i - 1, a = A[i1] - 'A', &c = C[i1][j];
            f = min(f, F[i1][j] + c);
            C[i][j] = c + (sa[a] == i1 && sb[a] >= j) - (ea[a] == i1 && eb[a] < j);
        }
        if(j) {
            int j1 = j - 1, b = B[j1] - 'A', &c = C[i][j1];
            f = min(f, F[i][j1] + c);
            C[i][j] = c + (sb[b] == j1 && sa[b] >= i) - (eb[b] == j1 && ea[b] < i);
        }
    }
    cout << F[n][m] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve() ;
    return 0;
}