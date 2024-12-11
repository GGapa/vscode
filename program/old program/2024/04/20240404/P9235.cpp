// P9235 [蓝桥杯 2023 省 A] 网络稳定性
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
using AI = array<int ,3>;
typedef long long ll;

vector<int> F;
int find(int x) {
    return (x == F[x] ? x : F[x] = find(F[x]));
}
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >>  m >> q;
    vector<AI> A(m +1);
    F.resize(n + 1), iota(F.begin(), F.end(), 0);
    rep(i, 1, m) cin >> A[i][1] >> A[i][2] >> A[i][0];
    sort(A.begin() + 1, A.end(), greater<>());
    vector<set<int>> S(n + 1);
    vector<int> ans(q + 1, -1);
    for(int i = 1, x, y; i <= q; i++)
        cin >> x >> y, S[x].insert(i), S[y].insert(i);
    rep(i, 1, m) {
        int x = find(A[i][1]),  y = find(A[i][2]);
        if(x == y) continue;
        if(S[x].size() > S[y].size()) swap(x, y);
        for(auto j : S[x]) 
            S[y].count(j) ? (ans[j] = A[i][0]) : (S[y].insert(j), 0);
        F[x] = y;
    }
    rep(i, 1, q ) cout << ans[i] << "\n";
    return 0;
}
