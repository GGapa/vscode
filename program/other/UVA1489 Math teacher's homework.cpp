#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int mod = 1000000003;

int n, m; 
int F[50][32][2], A[50];
LL mul[33];

int dfs(int x, int val, int len) {
    val &= ~((1 << len) - 1);
    if(x == n) return val == 0;
    int t = (val >> len) & 1, &f = F[x][len][t];
    if(f != -1) return f;
    f = 0;
    int res = 0;
    per(i, __lg(A[x]), 0) if(A[x] >> i & 1) 
        (f += dfs(x + 1, val ^ res, max(i, len)) * mul[min(i, len)] % mod) %= mod, res |= (1 << i);
    return f;
}

void solve() {
    rep(i, 0, n - 1) cin >> A[i], A[i]++;
    memset(F, -1, sizeof(F));
    cout << dfs(0, m, 0) << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // int T; cin >> T;
    mul[0] = 1;
    rep(i, 1, 32) (mul[i] = mul[i - 1] * 2) % mod;
    while(cin >> n >> m && (n || m)) solve();
    return 0;
}
/*

*/