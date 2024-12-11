#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const double eps = 1e-10;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, L; cin >> n >> L;
    list<array<double, 2>> q;
    double ans = 0;
    for(int i = 1; i <= n; i++) {
        double t, v;
        cin >> t >> v;
        t *= v;
        double tmp = v;
        while(!q.empty() && v > eps) {
            if(v - q.back()[0] > eps) {
                v -= q.back()[0]; ans -= q.back()[1];
                q.pop_back();
            }
            else {
                q.back()[1] /= q.back()[0];
                ans -= q.back()[1] * v;
                q.back()[1] *= (q.back()[0] -= v);
                v = 0;
            }
        }
        v = tmp;
        q.push_front({v, t}); ans += t;
        while(q.size() > 1 &&  (*next(q.begin()))[1] / (*next(q.begin()))[0] > q.front()[1] / q.front()[0]) {
            auto fi = q.front(); q.pop_front();
            q.front()[1] += fi[1], q.front()[0] += fi[0];
        }
        cout << fixed << setprecision(9) << ans / L << '\n';
    }   
    return 0;
}