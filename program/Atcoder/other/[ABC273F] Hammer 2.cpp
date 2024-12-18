// [ABC273F] Hammer 2
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>; 
const int N = 1500 * 2 + 10;
const ll INF = 1e18;

ll F[N][N][2]; //F[l][r] 在左端点还是在右端点。

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, x; cin >> n >> x;
    vector<array<int, 2>> A{{-1, -1}, {x, 0}, {0, 0}};
    vector<int> H(2 * n + 3);
    for(int i = 1, x; i <= n; i++) cin >> x, A.push_back({x, i});   //墙壁
    for(int i = 1, x; i <= n; i++) cin >> x, A.push_back({x, -i});  //锤子
    sort(A.begin() + 1, A.end());

    int st;
    rep(i, 1, 2 * n + 2) {
        auto &a = A[i];
        if(a[0] == 0) st = i;
        if(a[1] < 0) H[-a[1]] = i;
    }
    
    memset(F, -1, sizeof(F));
    function<ll(int, int, int)> dp = [&](int l, int r, int p) {
        // cout << l << " " << r << " " << p << '\n';
        auto &f = F[l][r][p];
        if(f != -1) return f;
        int lx = A[l][0], rx = A[r][0], nw = (p ? rx : lx);
        f = INF;
        if(lx == x || rx == x) return f = 0;
        if(r < 2 * n + 2) {
            int i = A[r + 1][1];
            if(i <= 0 || (l <= H[i] && H[i] <= r)) 
                f = min(f, dp(l, r + 1, 1) + A[r + 1][0] - nw);
        }
        if(l > 1) { 
            int i = A[l - 1][1];
            if(i <= 0 || (l <= H[i] && H[i] <= r)) 
                f = min(f, dp(l - 1, r, 0) + nw - A[l - 1][0]);
        }
        return f;
    };

    ll ans = dp(st, st, 0);
    cout << (ans == INF ? -1 : ans);
    return 0;
}

/*
假设原点是一个墙，其钥匙就在原点。

考虑在墙之间进行转移
定义 F[i][j] 为到达墙 i 打不打破墙 j(0/1) 的最小距离，初始化为 INF
但这么做似乎并不可行，因为有些时候会在开墙的途中捡到其他墙壁的钥匙。

定义 F[l][r] 为打破墙 l 和墙 r 的最小距离。
F[l][r + 1] 若钥匙就在 F[l][r] 内可以直接转移。若不在 F[l][r] 内，可以考虑
拿状态来更新好像不好实现。
考虑用状态来去更新。

区间 DP 常用套路，增加一个标记，表示在左还是在右边。


*/