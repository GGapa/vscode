// E
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1), C(n + 1);
    int cnt = 0;
    for(int it = 1; it <= n; ) {
        k = min(k, n - it + 1);
        int hf = k / 2;
        cnt++;
        rep(i, 0, k - 1) {
            C[it + i] = cnt;
            A[it + i] = it + hf - i;
            if(A[it + i] < it) A[it + i] += k;
        }
        it += k;
    }
    rep(i, 1, n) cout << A[i] << " \n"[i == n];
    cout << cnt << '\n';
    rep(i, 1, n) cout << C[i] << " \n"[i == n]; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}