#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;
const int N = 30 + 5;
int A[N], F[N][N], rt[N][N];

int dfs(int l, int r) {
    auto &f = F[l][r];
    if(f != -1) return f;
    if(l > r) return f = 1  ;
    if(l == r) return rt[l][r] = l, f = A[l];
    f = 0;
    rep(i, l, r) {
        int t = dfs(l, i - 1) * dfs(i + 1, r) + A[i];
        if(t > f) f = t, rt[l][r] = i;
    }
    return f;
}

void out(int l, int r) {
    if(l > r) return ;
    cout << rt[l][r] << " ";
    if(l == r) return;
    int t = rt[l][r];
    out(l, t - 1), out(t + 1, r);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    rep(i, 1, n) cin >> A[i];
    memset(F, -1, sizeof(F));
    cout << dfs(1, n) << '\n';
    out(1, n);
    return 0; 
}
