#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, s1, s2; cin >> n >> s1 >> s2;
    vector<int> A(n + 1), id(n);
    rep(i, 1, n) cin >> A[i];
    iota(id.begin(), id.end(), 1);
    sort(id.begin(), id.end(), [&](const int x, const int y) {
        return A[x] > A[y];
    });
    int sa = 0, sb = 0;
    vector<int> aa, ab;
    for(auto i : id) {
        if((aa.size() + 1) * s1 < (ab.size() + 1) * s2) aa.emplace_back(i);
        else ab.emplace_back(i);
    }
    cout << aa.size() << " ";
    for(auto a : aa) cout << a << " ";
    cout << '\n';

    cout << ab.size() << " ";
    for(auto a : ab) cout << a << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}