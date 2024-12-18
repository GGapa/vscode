#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s; cin >> s;
    int n; cin >> n;
    using VS = vector<string>;
    using VI = vector<int>;
    vector<VS> A(n + 10, VS(20));
    vector<int> F(s.size() + 10, 2e9);
    vector<int> C(n + 10);
    rep(i, 1, n) {
        cin >> C[i];
        rep(j, 1, C[i]) cin >> A[i][j];
        sort(A[i].begin() + 1, A[i].begin() + 1 + C[i]);
    }
    F[0] = 0;
    rep(cc, 1, n) {
        rep(i, 1, C[cc]) { 
            per(k, s.size(), 0) if(s.substr(k, A[cc][i].size()) == A[cc][i]) 
                F[k + A[cc][i].size()] = min(F[k + A[cc][i].size()], F[k] + 1);
        }
    }
    int ans = F[s.size()];
    cout << (ans == 2e9 ? -1 : ans) << '\n';
    return 0;
}