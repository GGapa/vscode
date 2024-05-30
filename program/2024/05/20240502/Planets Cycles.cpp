// Planets Cycles 
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), vis(n + 1), ans(n + 1);
    rep(i, 1, n) cin >> A[i];
    int siz = 0, flag, it, idx;
    function<int(int)> dfs = [&](int x) {
        if(vis[x]) {
            if(ans[x] == 0) return flag = 0, it = x, siz;
            else return flag = 1, ans[x] + 1;
        }
        vis[x] = ++idx;
        siz = vis[x]  - vis[A[x]]  + 1;
        ans[x] = dfs(A[x]);
        if(x == it) flag = 1;
        return ans[x] + flag;
    };
    rep(x, 1, n) if(!vis[x]) siz = 0, idx = 0, dfs(x);
    rep(i, 1, n) cout << ans[i] << " \n"[i == n];
    return 0;
}