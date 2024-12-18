#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 100 + 5;

int A[N][N][N];
int sum[N][N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;

    rep(i, 1, n) rep(j, 1, n) rep(k, 1, n) cin >> A[i][j][k];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                sum[i][j][k]=sum[i-1][j][k]+sum[i][j-1][k]+sum[i][j][k-1]-sum[i-1][j-1][k]-sum[i-1][j][k-1]-sum[i][j-1][k-1]+sum[i-1][j-1][k-1]+A[i][j][k];
            }
        }
    }
    int q; cin >> q;
    for(int i = 1, la, ra, lb, rb, lc, rc; i <= q; i++) {
        cin >> la >> ra >> lb >> rb >> lc >> rc;
        cout << sum[ra][rb][rc] - sum[la-1][rb][rc] - sum[ra][lb-1][rc] - sum[ra][rb][lc-1] + sum[la-1][lb-1][rc] + sum[ra][lb-1][lc-1] + sum[la-1][rb][lc-1] - sum[la-1][lb-1][lc-1] << '\n';
    }
    return 0;
}