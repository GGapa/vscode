#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<array<int, 2>> A(n + 1);
    rep(i, 1, n) cin >> A[i][0] >> A[i][1];
    using AI = array<int, 2>;
    vector<int> id(n);
    iota(id.begin(), id.end(), 1);
    sort(id.begin(), id.end(), [&](const int x, const int y) {
        if(min(A[x][0], A[x][1]) == min(A[y][0], A[y][1])) return max(A[x][0], A[x][1]) < max(A[y][0], A[y][1]);
        return min(A[x][0], A[x][1]) < min(A[y][0], A[y][1]);
    });
    for(auto i : id) cout << A[i][0] << " " << A[i][1] << " ";
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