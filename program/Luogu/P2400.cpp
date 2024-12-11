#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

int len(int x) {return to_string(x).size(); }
const int INF = 1e9;


signed main() {
    // cerr <<(int)'A' << " " << (int)'1' << " " << (int)("1" > "A") << '\n';
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<VI> F(n + 1, VI(n + 1, INF));
    vector<vector<string>> ans(n + 1, vector<string>(n + 1, ""));
    rep(i, 1, n) F[i][i] = 1, ans[i][i] = s[i];
    rep(p, 2, n) for(int i = 1, j = p; j <= n; j++, i++) {
        rep(k, i, j - 1) if(F[i][j] > F[i][k] + F[k + 1][j]) F[i][j] = F[i][k] + F[k + 1][j], ans[i][j] = ans[i][k] + ans[k + 1][j];
        rep(k, 1, p - 1) if(p % k == 0) {
            bool tag = 1;
            for(int l = k; l + i <= j; l++) if(s[l + i] != s[l % k + i]) {
                tag = 0; break;
            }
            if(tag) if(F[i][j] > F[i][i + k - 1] + 2 + len(p / k)) {
                F[i][j] = F[i][i + k - 1] + 2 + len(p / k);
                ans[i][j] = to_string(p / k) + '(' + ans[i][i + k - 1] + ')';
            }
        }   
    }
    cout << ans[1][n] << '\n';
    return 0;
}