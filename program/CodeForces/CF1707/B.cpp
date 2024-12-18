#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1), B;
    rep(i, 1, n) cin >> A[i];

    rep(o, 1, n - 1) {
        vector<int>(0).swap(B);
        B.emplace_back(0);
        rep(i, 2, (int)A.size() - 1) B.emplace_back(A[i] - A[i - 1]);
        sort(B.begin(), B.end());
        if(B[1] != 0) A = B;
        else {
            per(i, (int)B.size() - 2, 0) if(B[i + 1] == 0) {
                A = vector<int>(B.begin() + i, B.end());
                break;
            }
        }
    }
    cout << A.back() << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}