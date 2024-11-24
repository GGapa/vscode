#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<array<int, 2>> A(n + 1);
    rep(i ,1, n) cin >> A[i][0], A[i][1] = i;
    sort(A.begin() + 1, A.end());
    cout << A[n - 1][1] << '\n';
    return 0;
}