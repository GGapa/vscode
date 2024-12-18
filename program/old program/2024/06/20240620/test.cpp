#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
typedef long long ll;
using VI = vector<int>;

int n; 

void solve() {
    int m = n * 2;
    vector<pair<int, int>> A(m + 1);
    rep(i, 0, m - 1) {
        string s; cin >> s;
        cin >> A[i].first >> A[i].second;
    }
    int tp = (1 << m) - 1;
    auto dis = [&](int i, int j ) {
        return (A[i].first - A[j].first) * (A[i].first - A[j].first) + (A[i].second - A[j].second) * (A[i].second - A[j].second);
    };
    vector<VI> F(m, VI(tp + 1, 1e9));
    F[0][0] = 0;
    rep(i, 1, m - 1) rep(s, 0, tp)
    rep(j, 0, m - 1) if((s >> j) & 1) 
        F[i][s] = min(F[i][s], F[i - 1][s ^ (1 << i) ^ (1 << j)] + dis(i, j));
    cout << fixed << setprecision(2) << sqrt(F[m - 1][tp]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int ca = 1; cin >> n && n; ca++) {
        if(ca != 1) cout << '\n';
        cout << "Case " << ca << ": ";
        solve();
    }
    return 0;
}