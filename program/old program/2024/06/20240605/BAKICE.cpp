//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 100 + 5;
char A[N][N];


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> cha(1), peo(1);
    rep(i, 1, n) rep(j, 1, m) {
        cin >> A[i][j];
        if(A[i][j] == 'X') peo.push_back({i, j});
        if(A[i][j] == 'L') cha.push_back({i, j});
    }
    auto gdis = [&](int i, int j) {
        return (peo[i].first - cha[j].first) * (peo[i].first - cha[j].first) + (peo[i].second - cha[j].second) * (peo[i].second - cha[j].second);
    };
    vector<tuple<int, int, int>> dis;
    rep(i, 1, (int)peo.size() - 1) rep(j, 1, (int)cha.size() - 1) dis.push_back({gdis(i, j), i, j});
    vector<int> ux(peo.size()), ul(cha.size()), rd(cha.size(), 0), boo(peo.size()), ad(cha.size(), 1);
    int ans = 0;
    sort(dis.begin(), dis.end());
    for(auto tp : dis) {
        int d, i, j;
        tie(d, i, j) = tp;
        if(rd[j] == d && !boo[i] ) ans += ad[j], boo[i] = 1, ad[j] = 0;
        if(ux[i] || ul[j] || boo[i] || rd[j] == d) continue;
        ux[i] = 1; ul[j] = 1;
        rd[j] = d;
    }
    cout << ans << '\n';
    return 0;
}