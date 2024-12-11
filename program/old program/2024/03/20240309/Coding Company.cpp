// Coding Company
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 100 + 5;
// #define int long long
ll F[N][N][10000];
const int mod = 1e9 + 7;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x; cin >> n >> x;
    vector<int> A(n +1);
    ll sum = 0;
    rep(i, 1, n) cin >> A[i], sum += A[i];
    sort(A.begin() + 1, A.end(), greater<>());
    F[1][0][0] = 1;
    rep(i, 1, n) rep(j, 0, i) rep(k, 0, sum) {
        ll a = A[i], &f = F[i][j][k];
        if(j && k >= a)     //能不能减少一个组
            (F[i + 1][j - 1][k - a] += 1ll * f * j % mod) %= mod; 
        if(j + 1 <= n && k + a <= sum) // 添加一个组
            (F[i + 1][j + 1][k + a] += f) %= mod;
        (F[i + 1][j][k] += 1ll * f * (j + 1) % mod) %= mod;  //加入一个现有的.
    } 
    ll ans = 0;
    rep(k, 0, x) (ans += F[n + 1][0][k]) %= mod;
    cout << ans << '\n';
    return 0;
}