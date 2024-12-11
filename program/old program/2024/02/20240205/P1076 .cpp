//P1076 [NOIP2012 普及组] 寻宝
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 10000 + 5, mod = 20123;

int n, m;
int typ[N][200], nxt[N][2000];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    rep(i, 1, n) {
        int cnt = 0;
        rep(j, 0, m - 1)  cin >> typ[i][j] >> nxt[i][j], cnt += (typ[i][j] == 1);
        typ[i][m] = cnt;
    }
    int s, ans = 0; cin >> s;
    int it = 1;
    for(; it <= n; ) {
        ans = (ans + nxt[it][s]) % mod; 
        int t = 0;
        int j = 0;
        for(j = s; ; j++) {
            if(j == m) j = 0;
            if(typ[it][j] == 1)  t++;
            if(t == (nxt[it][s] - 1) % typ[it][m] + 1) break;
        }
        s = j;
        it++;
    }
    cout << ans << '\n';

    return 0;
}