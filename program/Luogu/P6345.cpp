#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> vis(51), A(n + 1);
    int sum = 0;
    rep(i, 1, n) cin >> A[i];
    static bitset<51 * 501> bs[501];

    sort(A.begin(), A.end());
    rep(i, 1, n - 1) vis[A[i]] = 1;

    bs[0][0] = 1;
    rep(i, 1, n - 1) {
        for(int j = 1; A[i] + j <= 50; j++) if(vis[A[i] + j]) bs[i] |= (bs[i - 1] << j);
        bs[i] |= bs[i - 1];
    }

    rep(i, 0, 50 * n) if(bs[n - 1][i]) cout << i  << " ";

    return 0;
}
