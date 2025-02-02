#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 810, fx[] = {-1, 1, 0, 0}, fy[] = {0, 0, -1, 1};

int vis[N][N], ban[N][N], A[N][N], B[17];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    int K, n, m; cin >> K >> n >> m;
    string s; cin >> s;

    vector<AI<2>> V;
    rep(i, 1, n) rep(j, 1, m) cin >> A[i][j], V.push_back({i, j});

    rep(S, 0, 15) {
        for(int j = 0, k = 0; j < 2 * K; j++)
            (S >> string("NSWE").find(s[j % K]) & 1) ? B[S] = max(B[S], ++k) : k = 0;
        if(B[S] == 2 * K) B[S] = INT_MAX;
    }

    int ans, cnt; ans = cnt = INT_MAX;
    shuffle(V.begin(), V.end(), mt19937(chrono::system_clock::now().time_since_epoch().count()));
    memset(vis, -1, sizeof(vis));

    for(int i = 0, x, y; i < n * m; i++) {
        int sz = ban[x = V[i][0]][y = V[i][1]] = 1;
        if(!A[x][y]) continue;
        queue<AI<2>> q;
        q.push({x, y}), vis[x][y] = i;
        while(!q.empty()) {
            auto nw = q.front(); q.pop();
            rep(k, 0, 3) {
                int nx = nw[0] + fx[k], ny = nw[1] + fy[k];
                if(!A[nx][ny] || vis[nx][ny] == i) continue;
                int S = 0;
                rep(t, 0, 3) S |= (vis[nx + fx[t]][ny + fy[t]] == i) << t;
                if(B[S] < A[nx][ny]) continue;
                if(ban[nx][ny]) goto nxt;
                q.push({nx, ny}); vis[nx][ny] = i; sz++;
            }
        }
        if(sz < ans) ans = cnt = sz;
        else if(sz == ans) cnt += sz;

        // if(sz == 1) cerr << x << " " << y << '\n'; 

        nxt: void();
    }
    cout << ans << '\n';
    cout << cnt << '\n';
    return 0;
}
/*

首先，我们可以求出来如果对应动物四个方向上全部被感染，那么最长的连续暴露时间是多久
状压 + O(n) 可以求出
现在我就
*/