// [ABC271D] Flip and Adjust
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, s; cin >> n >> s;
    vector<array<int, 2>> A(n + 1);
    rep(i, 1, n) cin >> A[i][0] >> A[i][1];
    if(n * 100 < s) return cout << "No\n", 0;
    vector<VI> F(n + 1, VI(n * 100 + 10, -1));
    function<bool(int, int)> dfs = [&](int x, int v) {
        auto &f = F[x][v];
        if(v > s || F[x][v] != -1) return f = 0;
        f = 0;
        if(x == 0) {
            if(v == s) return cout << "Yes\n", f = 1;
            return f = 0;
        }
        rep(i, 0, 1) {
            if(dfs(x - 1, v + A[x][i])) {
                cout << (i ? "T" : "H");
                return f = 1;
            }
        }
        return f;
    }; 
    if(!dfs(n, 0)) cout << "No\n"; 
    return 0;
}