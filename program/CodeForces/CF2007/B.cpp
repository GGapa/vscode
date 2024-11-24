#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using ll = long long;
using VI = vector<int>;

void solve() {
    int n, m; cin >> n >> m;
    vector<int> A(n + 1) ;
    rep(i, 1, n) cin >> A[i];
    sort(A.begin() + 1, A.end()) ;
    int t1 = A[n], t2 = 0;
    per(i, n, 1) if(A[i] != t1) {
        t2 = A[i]; break;
    }
    while(m--) {
        char c; int l, r; 
        cin >> c >> l >> r;
        int ad = 0;
        if(c == '+') ad = 1;
        else ad = -1;
        if(l <= t1 && t1 <= r) t1 += ad;
        if(l <= t2 && t2 <= r) t2 += ad;
        if(t1 < t2) swap(t1, t2) ;
        cout << t1 << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}