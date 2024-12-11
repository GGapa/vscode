#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

int n;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    vector<int > a(n + 1), b(n + 1), c(n + 1);
    rep(i, 1, n) cin >> a[i]; b = a;
    rep(i, 1, n) {
        int it = i;
        rep(j, 1, 3) it = a[it];
        b[i] = it;
    }
    rep(i, 1, n) cin >> c[i];
    rep(i, 1, n) cout << c[b[i]] << '\n';
    // for(auto i : b) cout << i << '\n';
    return 0;
}