// Fixing the Great Wall
// 未来费用
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1000 + 5;

int n;
double V, x;
double S[N];

struct Node {
    double x, c, dt;   //个点的位置，现在立即修复的花费，以及每过单位时间修复花费的增长量。
}A[N];
double F[N][N][2];
// bool vis[N][N][2

double cost(int u, int v, int i, int j) {
    double tmp = (i > 0 ? S[j] - S[i - 1] : 0);
    return 1.0 * (S[n] - tmp) * abs(u - v) / (1.0 * V);
}

double dp(int i, int j, int k) {
    if(i == 1 && j == n) return 0;
    auto &f = F[i][j][k];
    if(f != -1.0) return f;
    int nw = (k == 1 ? A[j].x : A[i].x);
    f = 1e36;
    if(i > 1) f = min(f, dp(i - 1, j, 0) + cost(A[i - 1].x, nw, i, j));
    if(j < n) f = min(f, dp(i, j + 1, 1) + cost(nw, A[j + 1].x, i, j));
    return f;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(; cin >> n >> V >> x && n; ) {
        int sc = 0;
        rep(i, 1 ,n) cin >> A[i].x >> A[i].c >> A[i].dt, sc += A[i].c;
        sort(A + 1, A + 1 + n, [](const Node & X, const Node & Y) {
            return X.x < Y.x;
        });
        rep(i, 1, n) S[i] = S[i - 1] + A[i].dt;
        A[n + 1].x = 1e36; A[0].x = -1e36;
        rep(i, 1, n) rep(j, 1, n) rep(k, 0, 1) F[i][j][k] = -1;
        double ans = 1e36;
        rep(i, 1, n + 1) if(A[i - 1].x <= x && x <= A[i].x) {
            if(i > 1) 
                ans = min(ans, dp(i - 1, i - 1, 0) + cost(x, A[i - 1].x, -1, -1));
            if(i <= n ) 
                ans = min(ans, dp(i, i, 0) + cost(x, A[i].x, -1, -1));
            break;
        }
        // cout << floor(ans + sc) << '\n';
        printf("%.0f\n", floor(ans + sc) );
    }
    return 0;
}