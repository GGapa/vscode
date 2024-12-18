#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 1e3 + 5;

int F[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("seq.in", "r", stdin);
    freopen("seq.out", "w", stdout);
    int n; cin >> n;
    F[0] = 1, F[1] = 1;
    auto check = [&](int i, int j) {
        for(int k = 1; i - 2 * k >= 0; k++) if(F[i] - F[i - k] == F[i - k] - F[i - 2 * k]) return false;
        return true;
    };
    rep(i ,2, n) {
        for(int j = 1; ; j++) {
            F[i] = j;
            if(check(i, j)) break;
        }
    }
    cout << F[n] << '\n';
    return 0;
}
