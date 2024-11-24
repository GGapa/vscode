#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;



void solve() {
    string s; cin >> s;
    int n = s.size(); s = " " + s;
    vector<int> z(n + 100);
    auto getZ = [&](const string &a) {
        z[1] = n;
        for(int i = 2, l = 0, r = 0; i <= n; i++) {
            int &j = z[i] = i > r ? 0 : min(r - i + 1, z[i - l + 1]) ;
            while(a[1 + j] == a[i + j] && j < n) j++;
            if(i + j - 1 > r) r = i + j - 1, l = i;
        }
    };
    int q; cin >> q;

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}