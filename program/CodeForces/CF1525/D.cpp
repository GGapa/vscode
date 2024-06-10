//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), pos;
    int cnt = 0;
    rep(i, 1, n) cin >> A[i], cnt += A[i];
    rep(i, 1, n) if(A[i]) pos.emplace_back(i);
    vector<VI> F(n + 1, VI(cnt + 1, 1e9));       //F[i][j] 前 i 个人，有 j 人归位的最小贡献.
    rep(i, 0, n) F[i][0] = 0;
    rep(j, 1, cnt) rep(i, 1, n) {
        if(A[i] == 0) F[i][j] = min(F[i - 1][j], F[i - 1][j - 1] + abs(pos[j - 1] - i));
        else F[i][j] = F[i - 1][j];
    }
    cout << F[n][cnt] << '\n';
    return 0;
}