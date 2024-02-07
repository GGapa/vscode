//Books  CF279B


#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, t, ans = 0 ;
    cin >> n >> t;
    vector<int> a(n);
    for(int & i : a) cin >> i;
    for(int l = 0, r = 0, s = 0; l < n && r < n; l++) {
        while(r < n && s + a[r] <= t) s += a[r++];
        ans = max(r - l, ans), s -= a[l];
    }
    cout << ans << '\n';
    return 0;
}