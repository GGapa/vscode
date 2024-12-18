//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int pri[] = {1, 2, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};

void solve() {
    int a, b, c; cin >> a >> b >> c;
    // if(a == b && b == 1) return cout << "1 1\n", void();
    cout << pri[a - c + 1] * pri[c] << " " << (pri[b - c + 1] + 2) * pri[c] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}

