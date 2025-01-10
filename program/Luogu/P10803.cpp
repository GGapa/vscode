#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e6 + 5;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;

    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i], A[i]++;

    vector<int> L(n + 1), R(n + 1);
    for(int x = sx, y = sy; x >= 1; x--) {
        y = min(y, A[x]);
        int dis = sx - x;
        R[x] = A[x] - y + dis;
        L[x] = y + dis - 1 ;
    }
    for(int x = sx, y = sy; x <= n; x++) {
        y = min(y, A[x]);
        int dis = x - sx;
        R[x] = A[x] - y + dis;
        L[x] = y + dis - 1;
    }

    rep(i, 1, n - 1) {
        L[i + 1] = min(L[i + 1], R[i] + 1);
        L[i + 1] = min(L[i + 1], L[i] + 1);
    }

    per(i, n, 2) {
        R[i - 1] = min(R[i - 1], L[i] + 1);
        L[i - 1] = min(L[i - 1], L[i] + 1);
    }

    vector<VI> st(n + 1, VI(__lg(n) + 1));
    rep(i, 1, n) st[i][0] = A[i];
    rep(j, 1, __lg(n)) for(int i = 1; (i + (1 << j) - 1) <= n; i++) 
        st[i][j] = min(st[i][j - 1], st[i + (1 << j - 1)][j - 1]);
    auto ask = [&](int l, int r) {
        if(l > r) swap(l, r);
        int t = __lg(r - l + 1);
        return min(st[l][t],st[r - (1 << t) + 1][t]);
    };

    auto dis = [&](int a, int b, int c, int d) {
        return abs(a - c) + abs(d - min(b, ask(a, c)));
    };

    int ans = dis(sx, sy, ex, ey);

    rep(i, 1, n)  {
        ans = min({ans, dis(i, 1, ex, ey) + L[i], dis(i, A[i], ex, ey) + R[i]});
    }
    
    cout << ans << '\n';

    return 0;
}
/*
显然，真正重要的点只可能是两端的点，
其中之一是二者的曼哈顿距离，使用穿梭的本质是到达更靠近左侧或右侧的点，所以只会穿梭一次。
先处理出到达左右两边的最短距离，接着左右距离相互更新。
5
3 1
2 8
7 10 9 9 0
*/