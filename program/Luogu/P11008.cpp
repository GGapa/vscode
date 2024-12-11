#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), vis(n * 2), B = A; vis[0] = 1;
    vector<VI> num(23, VI(2)), cnt = num;

    rep(i, 1, n) {
        if(i > 1) {
            cin >> A[i]; B[i] = A[i];
            A[i] ^= A[i - 1] ;
            vis[A[i]] = 1;
        }
        rep(j, 0, 22) num[j][i >> j & 1]++;         // 对原排列每一位统计 1 和 0 的个数
        rep(j, 0, 22) cnt[j][A[i] >> j & 1]++;      // 预处理每一位 0 1 两种集合的大小，实际上只需要处理 0 的集合就行了。
    }

    auto out = [&](int x) {
        if(vis[x]) return false;
        rep(i, 1, n) {
            if(i > 1) x ^= B[i];
            cout << x << " \n"[i == n];
        }
        return true;
    };

    bool tag = false;
    function<void(int, int)> dfs = [&](int x, int nw) {
        if(x == -1) return tag |= out(nw), void();
        if(tag) return ;
        rep(i, 0, 1) if(cnt[x][0] == num[x][i]) 
            dfs(x - 1, nw ^ (i << x)) ;
    };
    dfs(22, 0) ;
    
    assert(0);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}