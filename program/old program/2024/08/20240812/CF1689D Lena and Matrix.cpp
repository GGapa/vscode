#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m ; cin >> n >> m;
    vector<int> nx, ny;
    rep(i ,1, n) rep(j, 1, m) {
        char c; cin >> c;
        if(c == 'B') nx.emplace_back(i + j), ny.emplace_back(i - j);
    }
    sort(nx.begin(), nx.end()); sort(ny.begin(), ny.end()) ;
    auto calc = [&](int x, int y) {
        return max({x - nx[0], y - ny[0], nx.back() - x, ny.back() - y});
    }; 
    int ax = 0, ay = 0;
    rep(i ,1, n) rep(j, 1, m) if(calc(i + j,i - j) < calc(ax + ay, ax - ay)) 
        ax = i, ay = j;
    cout << ax << " " << ay << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}