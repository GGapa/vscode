#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n,k ; cin >> n >> k;
    vector<pair<int, int>> A;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        x %= k;
        if(x == 0) cout << i << " ";
        else A.emplace_back(x, i);
    }
    sort(A.begin(), A.end(), [&](const pair<int, int> x, const pair<int, int> y) {
        if(x.first == y.first) return x.second < y.second;
        return x.first > y.first;
    });
    for(auto p : A) cout << p.second << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}