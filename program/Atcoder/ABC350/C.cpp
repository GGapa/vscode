#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1), it(n + 1);
    rep(i, 1, n) cin >> A[i], it[A[i]] = i;
    vector<array<int, 2>> ans;
    rep(i, 1, n) {
        if(A[i] != i) {
            ans.push_back({i, it[i]});
            int t = A[i];
            swap(A[i], A[it[i]]);
            swap(it[t], it[i]);
        }
        // rep(j, 1, n) cout << A[j] << " \n"[j == n];
    }
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i[0] << " " << i[1] << '\n';
    return 0;
}