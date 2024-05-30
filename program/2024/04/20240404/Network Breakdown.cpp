// Network Breakdown
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
using AI = array<int, 2>;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, q; cin >> n >> m >> q;
    set<AI> s; 
    vector<AI> A(m + 1), Q(q + 1);  
    VI ans(q + 1), F(n + 1);
    function<int(int)> find = [&](int x) {return (x == F[x] ? x : F[x] = find(F[x]));};
    iota(F.begin(), F.end(), 0);
    rep(i, 1, m) {
        cin >> A[i][0] >> A[i][1];
        if(A[i][0] > A[i][1]) swap(A[i][0], A[i][1]);
    }
    rep(i, 1, q) {
        cin >> Q[i][0] >> Q[i][1];
        if(Q[i][0] > Q[i][1]) swap(Q[i][0], Q[i][1]);
        s.insert(Q[i]);
    }
    int cnt = n;
    rep(i, 1, m) if(!s.count(A[i])) {
        int x = find(A[i][0]), y = find(A[i][1]);
        if(x == y) continue;
        cnt--;
        F[x] = y;
    }
    per(i, q, 1) {
        int x = find(Q[i][0]), y = find(Q[i][1]);
        ans[i] = cnt;
        cnt -= (x != y);
        F[x] = y;
    }
    rep(i, 1, q) cout << ans[i] << '\n';
    return 0;
}