#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    vector<pair<int, int>> pos;
    rep(i, 1, n) pos.emplace_back(A[i], i);
    sort(pos.begin(), pos.end());
    int it = 0;
    vector<int> ans, tmp; 
    for(auto p : pos) {
        if(p.second < it || (tmp.size() && tmp.front() < p.first)) tmp.emplace_back(p.first + 1);
        else it = p.second, ans.emplace_back(p.first);
    }
    for(auto a : tmp) ans.emplace_back(a);
    for(auto a : ans) cout << a << " ";
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