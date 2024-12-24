#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

constexpr int mod = 1e9;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;

    vector<AI> itv(1);
    rep(i, 1, n) rep(j, i + 1, n) if(__gcd(i, j) == 1)
        itv.push_back({i, j});
    
    sort(itv.begin() + 1, itv.end(), [&](const AI &x, const AI &y) {
        return x[1] < y[1];
    });
    int m = itv.size() - 1;
    vector<VI> F(m + 1, VI(n + 1));
    F[0][1] = 1;
    rep(i, 1, m) {
        int l = itv[i][0], r = itv[i][1];
        rep(j, 1, n) {
            F[i][j] = F[i - 1][j];
            if(j <= r) {
                if(j >= l) (F[i][j] += F[i - 1][l]) %= mod;
                else (F[i][j] += F[i - 1][j]) %= mod;
            }
        }
    }
    cout << F[m][n] << '\n';
    return 0;
} 