#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int F[] = {0, 1, 2, 2, 3, 3, 4};

void solve() {
    int n; cin >> n;
    if(n <= 6) {
        cout << F[n] << '\n';
        rep(i ,1, n) cout << F[i] << " \n"[i == n];
    }
    else {
        cout << 4 << '\n';
        rep(i ,1, n) cout << i % 4 +  1 << " \n"[i == n];
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}