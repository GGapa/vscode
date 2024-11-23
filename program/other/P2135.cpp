#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 50 + 5;

int n; 
int A[N], w[N], F[N][N][1005];

int dfs(int l, int r, int k) {
    auto &f = F[l][r][k];
    if(f != -1) return f;
    if(l == r) return f = (w[r] + k) * (w[r] + k);
    if(l > r) return f = 0;
    f = dfs(l, r - 1, 0) + (w[r] + k) * (w[r] + k);
    rep(i, l, r - 1) if(A[i] == A[r]) f = max(f, dfs(l, i, w[r] + k) + dfs(i + 1, r - 1, 0));
    return f;
};

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    rep(i, 1, n) cin >> A[i] ;
    rep(i, 1, n) cin >> w[i] ;
    memset(F, -1, sizeof(F)) ;
    cout << dfs(1, n, 0) ;
    return 0;
}