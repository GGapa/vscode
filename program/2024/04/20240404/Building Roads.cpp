// Building Roads
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> F(n + 1), ans;
    iota(F.begin(), F.end(), 0);
    function<int(int)> find = [&](int x) {
        return (x == F[x] ? x : F[x] = find(F[x]));
    };
    for(int i = 1, x, y; i <= m; i++) 
        cin >> x >> y, F[find(x)] = F[find(y)];
    set<int> s;
    rep(i, 1, n) {
        int t = find(i);
        if(!s.count(t)) 
            s.insert(t), ans.push_back(i);
    }
    cout << s.size() - 1 << '\n';
    if(s.size() == 1) return 0;
    rep(i, 0, s.size() - 2)  
        cout << ans[i] << " " <<ans[i + 1] << '\n';
    return 0;
}