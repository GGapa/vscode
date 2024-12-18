#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int N = 3000 + 5;

array<int, 2> F[4][N][N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    auto work = [&](int x, int y) {
        int ii = x, jj = y;
        for(int i = 1; i <= 4; i++, swap(x, y), y = n + 1 - y) F[i % 4][ii][jj] = {x, y};
    };
    rep(i, 1, n) rep(j, 1, n) work(i, j);
    int t = n / 2 % 4;
    vector<string> s(n + 1);
    rep(i, 1, n) cin >> s[i], s[i] = " " + s[i];
    rep(i, 1, n) rep(j, 1, n) cout << s[F[t][i][j][0]][F[t][i][j][1]] << (j == n ? "\n" : "") ;
    return 0;
}