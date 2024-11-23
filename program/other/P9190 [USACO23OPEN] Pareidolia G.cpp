#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
using AI = array<int, 2>;

string ss = " bessie";
const int INF = 1e9;

AI merge(const AI &x, const AI &y) {
    if(x[0] != y[0]) return (x[0] < y[0] ? y : x);
    return (x[1] < y[1] ? x : y);
}

AI add(const AI &x, const AI&y) {
    return {x[0] + y[0], x[1] + y[1]};
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<vector<AI>> F(n + 1, vector<AI>(7, {-INF, INF}));
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    int cnt = 1;
    F[0][0] = {0, 0};
    rep(i, 1, n) {
        per(j, 6, 1) {
            if(s[i] == ss[j]) F[i][j] = merge(F[i][j], F[i - 1][j - 1]);
            F[i][j] = merge(F[i][j], add(F[i - 1][j], {0, A[i]}));
        }
        F[i][0] = merge(add(F[i][6], {1, 0}), F[i - 1][0]);
    }
    cout << F[n][0][0] << '\n' << F[n][0][1]  << '\n';
    return 0;
}