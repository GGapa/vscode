#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, p; cin >> n >> p;
    vector<int> A(n + 1);
    rep(i ,1, n) cin >> A[i];
    sort(A.begin(), A.end());
    vector<int> ans;
    rep(x, A[1], A[n]) {
        if(x + n - 1 < A[n] || x < A[1]) continue;
        LL mm = 1;
        for(int l = 1, r = 1, nw = x; l <= n; l++) {
            while(A[r + 1] <= nw && r < n) r++;
            (mm *= (r - l + 1)) %= p; nw++;
            if(mm == 0) break;
        }   
        if(mm % p) ans.push_back(x);
    }
    cout << ans.size() << '\n';
    for(auto a : ans) cout << a << " ";
    return 0;
}   