#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e5 + 5;

int n, k, m;
vector<pair<int, int>> tpl[N], tpr[N]; 
int le[20][N], ri[20][N], mx[20][20][N], mn[20][20][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> k >> m;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        if(u < v) tpr[u].emplace_back(v, 1), tpr[min(u + k, v)].emplace_back(v, -1);
        else      tpl[u].emplace_back(v, 1), tpl[max(u - k, v)].emplace_back(v, -1);
    }

    {
        multiset<int> s;
        rep(i, 1, n) {
            for(auto p : tpr[i]) {
                if(p.second == 1) s.insert(p.first);
                else s.erase(s.find(p.first));
            }
            if(s.size()) ri[0][i] = *s.rbegin();
            else ri[0][i] = i;
        }
        s.clear();

        per(i, n, 1) {
            for(auto p : tpl[i]) {
                if(p.second == 1) s.insert(p.first);
                else s.erase(s.find(p.first));
            }
            if(!s.empty()) le[0][i] = *s.begin();
            else le[0][i] = i;
        }
    }

    auto qmx = [&](int i, int l, int r) {
        int len = __lg(r - l + 1);
        return max(mx[i][len][l], mx[i][len][r - (1 << len) + 1]);
    };
    auto qmn = [&](int i, int l, int r) {
        int len = __lg(r - l + 1);
        return min(mn[i][len][l], mn[i][len][r - (1 << len) + 1]);
    };

    rep(i, 1, 19) {
        rep(j, 1, n) mx[i - 1][0][j] = ri[i - 1][j], mn[i - 1][0][j] = le[i - 1][j];
        rep(x, 1, 18) for(int y = 1; y + (1 << x) - 1 <= n; y++) {
            mx[i - 1][x][y] = max(mx[i - 1][x - 1][y], mx[i - 1][x - 1][y + (1 << x - 1)]);
            mn[i - 1][x][y] = min(mn[i - 1][x - 1][y], mn[i - 1][x - 1][y + (1 << x - 1)]);
        }
        if(i == 19) continue;
        rep(j, 1, n) {
            ri[i][j] = qmx(i - 1, le[i - 1][j], ri[i - 1][j]);
            le[i][j] = qmn(i - 1, le[i - 1][j], ri[i - 1][j]);
        }
    }

    // 以上是预处理。

    int q; cin >> q;
    for(int s, st; q--; ) {
        cin >> s >> st;
        int ans = 0, l = s, r = s;
        bool tag = 0;
        per(i, 18, 0) {
            int t = __lg(r - l + 1);
            int nl = qmn(i, l, r), nr = qmx(i, l, r);
            if(nl <= st && st <= nr) {
                tag = 1;
                continue;
            }
            l = nl, r = nr;
            ans += (1 << i);
        }
        int nl = qmn(0, l, r), nr = qmx(0, l, r);
        if(nl <= st && st <= nr) ans++;
        else ans = -1;
        cout << ans << '\n';
    }
    
    return 0; 
}