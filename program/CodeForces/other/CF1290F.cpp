#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 5, mod = 998244353;

int nxt(int x, int y, int ori) {
    if(x != y) return (x < y);
    return ori;
}

int n, m, tp; 
int x[N], y[N], F[31][25][25][25][25][2][2];

int dfs(int it, int px, int nx, int py, int ny, int tx, int ty) {
    if(it == 30) return (!px && !nx && !py && !ny && tx && ty);
    int &f = F[it][px][nx][py][ny][tx][ty];
    if(f != -1) return f;
    int up = (m >> it) & 1; 
    f = 0;
    rep(s, 0, tp) {
        int npx = px, nnx = nx, npy = py, nny = ny;     // 没有 npy QAQ
        rep(i, 0, n - 1) if(s >> i & 1) {
            if(x[i] > 0) npx += x[i];
            else nnx -= x[i];
            if(y[i] > 0) npy += y[i];
            else nny -= y[i];
        }
        if(((npx & 1) == (nnx & 1)) && ((npy & 1) == (nny & 1))) 
            (f += dfs(it + 1, npx >> 1, nnx >> 1, npy >> 1, nny >> 1, nxt(npx & 1, up, tx), nxt(npy & 1, up, ty))) %= mod;
    }
    // cerr << it << " " << px << " " << nx << " " << py << " " << ny << " " << tx << " " << ty << " " << f << '\n';
    return f;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    rep(i, 0, n - 1) cin >> x[i] >> y[i];
    tp = (1 << n) - 1;
    memset(F, -1, sizeof(F));
    cout << (dfs(0, 0, 0, 0, 0, 1, 1) - 1 + mod) % mod;
    return 0;
}