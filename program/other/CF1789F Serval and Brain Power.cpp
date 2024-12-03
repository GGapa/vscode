#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 80 + 5;

string s;
int n;
int pos[N];

namespace sub1 {
    int F[N][N];
    int work(int mid) {
        rep(i, 0, mid) rep(j, mid, n) F[i][j] = 0;
        rep(i, 1, mid) rep(j, mid + 1, n) {
            F[i][j] = max(F[i - 1][j], F[i][j - 1]);
            F[i][j] = max(F[i - 1][j - 1] + (s[i] == s[j]), F[i][j]);
        }
        return F[mid][n] * 2;
    }
}

namespace sub2 {
    int F[N][N][N];
    int work(int m1, int m2) {
        rep(i, 0, m1) rep(j, m1, m2) rep(k, m2, n) F[i][j][k] = 0;
        rep(i, 1, m1) rep(j, m1 + 1, m2) rep(k, m2 + 1, n) {
            F[i][j][k] = max({F[i - 1][j][k], F[i][j - 1][k], F[i][j][k - 1]});
            F[i][j][k] = max(F[i][j][k], F[i - 1][j - 1][k - 1] + (s[i] == s[j] && s[k] == s[j]));
        }
        return F[m1][m2][n] * 3;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int ans = 0;
    cin >> s; 
    n = s.size(); s = " " + s;

    rep(i, 1, n) ans = max(ans, sub1::work(i));
    rep(i, 1, n) rep(j, i + 1, n) ans = max(ans, sub2::work(i, j));

    int tp = (1 << min(n, 16)) - 1;
    rep(jj, 1, max(1, n - 15)) {
        rep(ss, 1, tp) {
            // vector<int>(0).swap(pos);
            int it = 0;
            rep(i, 0, min(n, 16) - 1) if(ss >> i & 1) pos[it++] = i + 1 + jj;
            int res = 0, cnt = 0;
            for(int i = 1, j = 0; i <= n; i++) {
                if(s[i] == s[pos[j]]) res++, j++;
                if(j >= it) {
                    if(cnt > 1) ans = max(ans, res);
                    j = 0; cnt++;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
/*
pjobbikkifzzaqmpozlfkyuafghgpjbbikizzampozilfkyuafghygpjbbikiozzampozalfkyuafghg
*/