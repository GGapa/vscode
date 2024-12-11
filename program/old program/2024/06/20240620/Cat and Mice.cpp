//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

struct Node {
    int x, y, t;
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<Node> A(n + 2);
    auto dis = [&](int i, int j) {
        return sqrt(1ll * (A[i].x - A[j].x) * (A[i].x - A[j].x) + 1ll * (A[i].y - A[j].y) * (A[i].y - A[j].y)) ;
    };
    rep(i, 0, n - 1) cin >> A[i].x >> A[i].y >> A[i].t;
    double pw;  cin >> pw;
    A[n].x = 0, A[n].y = 0;
    int tp = (1 << n) - 1;
    
    auto check = [&](double v) {
        vector<vector<double>> F(tp + 1, vector<double>(n + 1, INT_MAX));
        double ti;
        rep(i, 0, n - 1) if((ti = dis(n, i) / v) <= A[i].t) F[(1 << i)][i] = ti;
         rep(s, 1, tp) rep(i, 0, n - 1) if((s >> i) & 1) 
            rep(j, 0, n - 1) if(!((s >> j) & 1)) {
                int bt = __builtin_popcount(s);
                double nv = v * pow(pw, bt);
                ti = F[s][i] + dis(i, j) / nv;
                if(ti > A[j].t) continue;
                F[s ^ (1 << j)][j] = min(F[s ^ (1 << j)][j], ti);
            } 
        if(*min_element(F[tp].begin(), F[tp].end()) < 2e9) return true;
        return false;
    };
    double l = 0, r = 1e9, ans;
    const double eps = 1e-10;
    while(r - l > eps) {
        double mid = (l + r) / 2;
        if(check(mid)) r = mid, ans = r;
        else l = mid;
    }
    cout << fixed << setprecision(20) << ans << '\n';
    return 0;
}