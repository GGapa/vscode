#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

int n, m;
const int INF = 1e9 ;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    bool tag = 0;
    if(n > m) swap(n, m), tag = 1;
    int q; cin >> q;
    unordered_map<int, unordered_map<int, int>> w;
    for(int i = 1, x, y; i <= q; i++) 
        cin >> x >> y, (tag ? w[y][x] : w[x][y]) = 1;
    vector<VI> F(2, VI(n + 1, -INF));   //F[i][j] 第 i 个最大值，盔甲是 j 所得到的最大 剑
    F[0][1] = 1;
    for(int c = 1; ; c++) {
        int i = c & 1;
        int i1 = i ^ 1;
        fill(F[i].begin(), F[i].end(), -INF);
        rep(j, 1, n) if(F[i1][j] >= 1) {
            auto &f = F[i][j];
            int ad = j + F[i1][j] + w[j][F[i1][j]];
            
            f = max(f, min(m, ad));
            F[i][min(n, ad)] = max(F[i][min(n, ad)], F[i1][j]);
        } 
        if(F[i][n] == m) return cout << c << '\n', 0;
    }
    return 0;
}