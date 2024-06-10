//君本凌云客，何故喜蓬蒿？
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

void solve() {
    vector<int> A(4);
    for(auto &i : A) cin >> i;
    auto B = A;
    vector<int> C = {max(A[0], A[1]), max(A[2], A[3])};
    sort(B.begin(), B.end()); sort(C.begin(), C.end());
    if(B[2] == C[0] && B[3] == C[1]) return cout << "YES\n", void();
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}