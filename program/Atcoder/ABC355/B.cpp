#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> A(1);
    for(int i = 1, x; i <= n; i++) 
        cin >> x, A.push_back({x, 1});
    for(int i = 1, x; i <= m; i++)
        cin >> x, A.push_back({x, 2});
        sort(A.begin() + 1, A.end());
    rep(i, 1, n + m - 1) if(A[i].second == A[i + 1].second && A[i].second == 1) return cout << "Yes\n", 0;
    cout << "No\n";
    return 0;
 }