#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

bool solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];   
    int l = A[1], r = A[1];
    bool tag = 1;
    rep(i, 2, n) {
        l = max(A[i], l - k + 1);
        r = min(A[i] + k - 1, r + k - 1);
        if(r < l) return false;      
    }
    return  (tag && l <= A[n] && A[n] <= r);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) cout << (solve() ? "YES" : "NO") << '\n';
    return 0;
}