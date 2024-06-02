#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<int> A(n, 1);
    for(int i = 1, x; i <= q; i++) {
        cin >> x; 
        A[x - 1] ^= 1;
    }
    cout << accumulate(A.begin(), A.end(), 0) << '\n';
    return 0;
}