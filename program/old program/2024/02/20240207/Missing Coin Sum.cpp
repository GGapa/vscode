//Missing Coin Sum
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n; cin >> n;
    vector<ll> a(n + 1); 
    rep(i, 1, n) cin >> a[i];
    ll s = 0, ans = 0;
    sort(a.begin(), a.end());
    rep(i, 1, n) {
        if(s + 1 < a[i]) break;
        s += a[i];
    }
    cout << s + 1 << '\n';
    return 0;
}