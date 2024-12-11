// Corporative Network
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
typedef long long ll;

void solve() {
    int n; cin >> n;
    vector<int> F(n + 1), D(n + 1);
    iota(F.begin(), F.end(), 0);
    function<int(int)> find = [&](int x) {
        if(x == F[x]) return x;
        int rt = find(F[x]);
        D[x] += D[F[x]];
        return F[x] = rt;
    };
    for(char c; cin >> c && c != 'O'; ) {
        int x, y;
        if(c == 'E') cin >> x, find(x), cout << D[x] << '\n';
        else cin >> x >> y, F[x] = y, D[x] = abs(x - y) % 1000;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}