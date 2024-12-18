#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<VI> op(n + 1);
    vector<int> ti(1);
    for(int i = 1, t, p; i <= m; i++) {
        cin >> t >> p;
        op[p].emplace_back(i);
        ti.emplace_back(t);
    }
    vector<int> tag(n + 1);
    vector<VI> F(n + 1);
    rep(i ,1, n) {
        if((LL)op[i].size() * (LL)op[i].size() >= m) {
            tag[i] = 1;
            F[i].resize(m + 1);
            int tp = 1;
            for(auto it : op[i]) {
                F[i][it] += (tp == 1) - (tp == 0);
                tp ^= 1;
            }
            rep(j, 1, m) F[i][j] += F[i][j - 1];
            rep(j, 1, m) F[i][j] = F[i][j - 1] + (F[i][j] ? (ti[j + 1] - ti[j]) : 0) ;
        }
    }
    map<pair<int, int>, int> ans;
    auto query = [&](int x, int y) {
        if(op[x].size() > op[y].size()) swap(x, y);
        if(ans.count({x, y})) return ans[{x, y}] ;
        int ret = 0;
        if(tag[y]) {
            for (int i = 0; i < (int)op[x].size(); i += 2) {
                int l = op[x][i], r = op[x][i + 1];
                ret += F[y][r - 1] - F[y][l - 1];   //右端点不能够取，左端点本来就不能取（前缀和）
            }
        }
        else {
            for(int i = 0, j = 0, vx = 0, vy = 0, lst = 0; i < op[x].size() && j < op[y].size(); ) {
                if(op[x][i] < op[y][j]) vx ^= 1, lst = op[x][i++];
                else vy ^= 1, lst = op[y][j++];
                if(vx && vy) ret += ti[min(op[x][i], op[y][j])] - ti[lst];
            }
        }
        return ans[{x, y}] = ans[{y, x}] = ret;
    };
    int q; cin >> q;
    for(int i = 1, x, y; i <= q; i++) {
        cin >> x >> y;
        cout << query(x, y) << '\n';
    }
    return 0; 
}