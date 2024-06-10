//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k; 
    vector<VI> G(k + 1, VI(k + 1, 1));
    vector<int> cur(k + 1, 1);
    string aa, ans;
    function<void(int)> dfs = [&](int x) {
        for(int &i = cur[x]; i <= k; i++) if(G[x][i]) G[x][i] = 0, dfs(i);
        aa += (x - 1 + 'a');
    };
    reverse(aa.begin(), aa.end());
    aa = "a";
    int cnt = 0;
    while(ans.size() < n) {
        rep(i, 1, k) cur[i] = 1;
        rep(i, 1, k) rep(j, 1, k) G[i][j] = 1;
        int st = *--aa.end() - 'a' + 1;
        aa = "";
        dfs(st);
        if(cnt) aa.erase(--aa.end());
        reverse(aa.begin(), aa.end());
        ans += aa;
        cnt++;
    }
    cout << ans.substr(0, n) << '\n';
    return 0;
}
