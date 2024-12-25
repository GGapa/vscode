#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1000 + 5;

int n, q, ans = 0;
int A[N][N], vis[N][N];

const string DIR = " LRUD";
const int fx[] = {0, 0, 0, -1, 1}, fy[] = {0, -1, 1, 0, 0};

bool check(int x, int y) {return x < 0 || y < 0 || x > n + 1 || y > n + 1;}

void dfs(int x, int y) {
    if(check(x, y) || vis[x][y]) return;
    if(1 <= x && x <= n && 1 <= y && y <= n) ans++; 
    vis[x][y] = 1;
    rep(i, 1, 4) {
        int nx = x + fx[i], ny = y + fy[i];
        if(check(nx, ny) || vis[nx][ny]) continue;
        if(A[nx][ny] == 0 || (nx + fx[A[nx][ny]] == x && ny + fy[A[nx][ny]] == y) || A[x][y] == i) dfs(nx, ny);
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> q;
    vector<array<int, 3>> op;
    for(int i = 1, x, y; i <= q; i++) {
        char c; cin >> x >> y >> c;
        op.push_back({x, y, c});
        A[x][y] = DIR.find(c);
    }
    
    dfs(0, 0);
    
    vector<int> out{ans};
    for_each(op.rbegin(), op.rend(), [&](const auto &a) {
        int x = a[0], y = a[1];
        A[x][y] = 0;
        bool tag = 0;
        rep(i, 1, 4) {
            int nx = x + fx[i], ny = y + fy[i];
            if(!check(nx, ny) && vis[nx][ny]) tag = 1;
        }
        if(tag) dfs(x, y);
        out.emplace_back(ans);
    });
    out.pop_back();
    for_each(out.rbegin(), out.rend(), [](const auto&a) {cout << n * n - a << '\n'; });
    return 0;
}