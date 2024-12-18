#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> a, b, c;
    unordered_map<int, int> mp;
    int n, m, l;
    auto get = [&](vector<int> &aa, int v) {
        aa.resize(v);
        for(auto &i : aa) cin >> i;
    };
    cin >> n ;get(a, n);
    cin >> m; get(b, m);
    cin >> l; get(c, l);
    for(auto i : a) for(auto j : b) for(auto k : c) mp[i + j + k] = 1;
    int tm; cin >> tm; 
    while(tm--) {
        int x; cin >> x;
        cout << (mp[x] == 1 ? "Yes\n" : "No\n");
    }
    return 0;
}
