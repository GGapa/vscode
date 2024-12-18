#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;


signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n, q; cin >> n >> q;

    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    
    sort(A.begin() + 1, A.end()) ;

    LL sum = 0; vector<LL> F(n + 1);
    F[0] = INT_MAX;
    rep(i, 1, n) F[i] = min(F[i - 1], 1ll * A[i] - i + 1), sum += A[i] - i + 1;

    while(q--) {
        int k; cin >> k;
        if(k < n) {
            cout << min(F[k] + k, 1ll * A[k + 1]) << " ";
            continue;
        }
        if((k - n) % 2 == 0) {
            cout << k + F[n] - max(0ll, (LL)ceil(((k - n) / 2 - (sum - F[n] * n)) * 1.0 / n)) << " ";
        }  
        else {
            LL mi = min(F[n - 1], 1ll * A[n] - k); 
            LL s = sum + n - 1 - k - mi * n;
            cout << k + mi - max(0ll, (LL)ceil(((k - n + 1) / 2 - s) * 1.0 / n)) << " ";
        }
    }
    return 0;
}