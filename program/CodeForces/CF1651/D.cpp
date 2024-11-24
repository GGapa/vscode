#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int fx[5] = {0, 1, -1, 0, 0}, fy[5] = {0, 0, 0, -1, 1};
map<pair<int, int>, int> mp;

void solve() {
    mp.clear();
    int n; cin >> n;
    vector<int> xx(n + 1), yy(n + 1), ax(n + 1), ay(n + 1);
    rep(i ,1, n) cin >> xx[i] >> yy[i], mp[{xx[i], yy[i]}] = i;
    queue<int> q;
    rep(i, 1, n) rep(j, 1, 4) {
        int nx = xx[i] + fx[j], ny = yy[i] + fy[j];
        if(mp[{nx, ny}]) continue;
        ax[i] = nx, ay[i] = ny;
        q.push(i);
        break;
    }
    while(!q.empty()) {
        int ii = q.front(); q.pop();
        int x = xx[ii], y = yy[ii];
        rep(i ,1, 4) {
            int nx = x + fx[i], ny = y + fy[i];
            int id = mp[{nx, ny}];
            if(!id || ax[id] || ay[id]) continue;
            ax[id] = ax[ii], ay[id] = ay[ii];
            q.push(id);
        }
    }
    rep(i ,1, n) cout << ax[i] << " " << ay[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; T = 1;
    while(T--) solve();
    return 0;
}