#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

const int mod = 998244353;

LL add(const LL x, const LL y) {
    return (x + y + mod) % mod;
} 
 
LL mul(const LL x, const LL y) {
    return (x * y % mod + mod) % mod;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    int sum = 0;
    rep(i, 1, n) cin >> A[i], sum += A[i];
    int m = sum * 2;
    vector<VI> F(n + 1, VI(m + 10));
    F[0][A[2] + sum] = 1;
    rep(i, 0, n - 3) rep(j, 0, m){
        if(!F[i][j]) continue;
        if(j == sum)
            F[i + 1][A[i + 3] + sum] = F[i][j];
        else{
            if(A[i + 3] + j <= m) F[i + 1][A[i + 3] + j] = add(F[i + 1][A[i + 3] + j], F[i][j]);
            if(A[i + 3] - j >= 0) F[i + 1][A[i + 3] - j + m] = add(F[i + 1][A[i + 3] - j + m], F[i][j]);
        }
	}
    LL ans = 0;
    rep(i, 0, m) ans = add(ans, F[n - 2][i]);
    cout << ans << '\n';
    return 0;
}