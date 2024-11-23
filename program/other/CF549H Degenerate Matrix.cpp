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
    LL a, b, c ,d; cin >> a >> b >> c >> d;
    double  ans = 1e19;
    LL t3 = a * d - b * c;
    rep(i, 0, (1 << 4) - 1) {
        double l = -1e10, r = 1e10;
        auto g = [&](int xx) {return (i >> xx & 1) ? -1 : 1;};
        LL t1 = g(0) * g(3) - g(2) * g(1);
        LL t2 = a * g(3) + d * g(0) - b * g(1) - c * g(2); 
        if(t1 != 0) {
            double a1 = 1.0 * (-t2 + sqrt(t2 * t2 - 4 * t1 * t3)) / 2 * t1;
            double a2 = 1.0 * (-t2 - sqrt(t2 * t2 - 4 * t1 * t3)) / 2 * t1;
            a1 = abs(a1), a2 = abs(a2);
            ans = min({ans, a1, a2});
        }
        else if(t2 != 0){
            ans = min(ans, abs(1.0 * t3 / t2));
        }
    }
    cout << fixed << setprecision(10) << abs(ans) << '\n';
    return 0;
}  