#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, m1, m2; cin >> n >> m1 >> m2;
    vector<LL> v, v1, v2;
    for(int i = 1; i * i <= m1; i++) if(m1 % i == 0) {
        v1.emplace_back(i);
        if(m1 / i != i) v1.emplace_back(m1 / i);
    }
    for(int i = 1; i * i <= m2; i++) if(m2 % i == 0) {
        v2.emplace_back(i);
        if(m2 / i != i) v2.emplace_back(m2 / i);
    }
    for(auto i : v1) for(auto j : v2) v.emplace_back(i * j);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    int cx=0, cnt=0;
    rep(i, 0, (int)v.size() - 1) if(v[i] <= 1ll * n * n) {
        int l = 0, r = i, best = 0;
        while(l <= r) {
            int mid = l + r >> 1;
            if((v[i] + v[mid] - 1) / v[mid] > n) l = mid + 1;
            else r = mid - 1, best = mid;
        }
        for(int j = best; j < v.size() && v[j] <= n; j++) if(v[i]%v[j]==0) {
            ++cnt;
            cx ^= v[j];
            break;
        }
    }
    cout << cnt << " " << cx << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}