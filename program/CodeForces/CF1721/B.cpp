#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int fx[] = {1, -1, 0, 0}, fy[] = {0, 0, 1, -1} ;

void solve() {
    int n, m; cin >> n >> m;
    int sx, sy, d; cin >> sx >> sy >> d;
    auto dis = [&](int x, int y) {return abs(sx - x) + abs(sy - y); }; 
    if((sx - 1 <= d || m - sy <= d) && (sy - 1 <= d || n - sx <= d)) return cout <<  -1 << '\n', void();
    else cout << n + m - 2  << '\n';    
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}