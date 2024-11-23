#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int p1, p2, h, s; 
    LL t1, t2; 
    cin >> p1 >> t1 >> p2 >> t2 >> h >> s;
    vector<LL> F(h + 1);
    rep(i, 1, h) {
        F[i] = min(F[max(i - (p1 - s), 0)] + t1, F[max(i - (p2 - s), 0)] + t2);
        rep(j, 1, i) {
            if (j * t1 >= t2) {
                LL dmg = (j - 1) * (p1 - s) + (j * t1 - t2) / t2 * (p2 - s) + (p1 + p2 - s);
                F[i] = min(F[i], F[max(0LL, i - dmg)] + j * t1);
            }
            if (j * t2 >= t1) {
                LL dmg = (j - 1) * (p2 - s) + (j * t2 - t1) / t1 * (p1 - s) + (p1 + p2 - s);
                F[i] = min(F[i], F[max(0LL, i - dmg)] + j * t2);
            }
        }
    }
    cout << F[h] << '\n';
    return 0;
}
