// A Spy in the Metro
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
 int INF = 1e9;
const int N = 50 + 5, T = 12500 + 5;
int ti[N], l[T][N], r[T][N], F[T][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n = 50, t = 1e5;
    for(int ca = 1, m1, m2; cin >> n && n; ca++) {
        memset(ti, 0, sizeof(ti));
        memset(r, 0, sizeof(r));
        memset(l, 0, sizeof(l));
        memset(F, 0x3f, sizeof(F));
        INF = F[0][0];
        cout << "Case Number " << ca << ": ";
        cin >> t;
        rep(i, 1, n - 1) cin >> ti[i];
        cin >> m1; 
        rep(i, 1, m1) {
            int x; cin >> x;
            l[x][1] = true;
            for(int j = 1; j < n; x += ti[j++]) 
                l[x + ti[j]][j + 1] = 1;
        }
        cin >> m2;
        rep(i, 1 ,m2)  {
            int x; cin >> x;
            r[x][n] = 1;
            for(int j = n - 1; j >= 1; x += ti[j--])
                r[x + ti[j]][j] = 1;
        }
        // rep(i, 1, t) rep(j, 1, n) F[i][j] = INF;
        F[t][n]  = 0;
        per(i, t - 1, 0) rep(j, 1, n) {
            int & f = F[i][j];
            f = F[i + 1][j] + 1;    //等待
            if(j < n && l[i][j]) f = min(f, F[i + ti[j]][j + 1]);
            if(j > 1 && r[i][j]) f = min(f, F[i + ti[j - 1]][j - 1]);
        }
        int ans = F[0][1];
        if(ans >= INF) cout << "impossible\n";
        else cout << ans << '\n';
    }
    return 0;
}
// F(i, j) 时刻 i ，车站 J 到达车站  T 所花费的最小等待时间