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
    int n, m; cin >> n >> m;
    vector<VI> A(n + 1, VI(m + 1)), H = A;
    rep(i, 1, n) rep(j, 1, m) cin >> A[i][j];
    rep(i, 1, n) rep(j, 1, m) H[i][j] = (A[i][j] == A[i - 1][j] ? H[i - 1][j] : 0) + 1;
    int ans = 0;
    rep(i, 1, n) {
        vector<pair<int, int>> stk;
        int cnt = 0;
        rep(j, 1, m) {
            int x = H[i][j];
            if(A[i][j] != A[i][j - 1]) stk.clear(), stk.push_back({0, j - 1}), cnt = 0; 
            while(stk.size() >= 1 && stk.rbegin()->first >= x) {
                cnt -= (stk.rbegin()->first - x) * (stk.rbegin()->second - (++stk.rbegin())->second);
                stk.pop_back();
            }
            stk.push_back({x, j});
            cnt += x;
            ans += cnt;
        }
    }
    cout << ans << '\n';
    return 0;
}