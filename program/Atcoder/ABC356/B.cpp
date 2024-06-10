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
    int n, m; cin >> n >> m;
    vector<int> A(m +1), cnt = A;
    rep(i, 1, m) cin >> A[i];
    rep(i, 1, n) rep(j, 1, m) {
        int x;cin >> x; cnt[j] += x;
    }
    rep(i, 1, m) if(cnt[i] < A[i]) return cout << "No\n", 0;
    cout << "Yes\n";
    return 0; 
}