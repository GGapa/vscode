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
    vector<int> A(n + 1);
    rep(i, 1 ,n) cin >> A[i];
    int mx, mn;
    while(*max_element(A.begin() + 1, A.end()) != (mn = *min_element(A.begin() + 1, A.end()))) {
        rep(i, 1, n) if(A[i] != mn) {
            A[i] %= mn;
            if(A[i] == 0) A[i] += mn;
        }
    }
    cout << A[1] << '\n';
    return 0;
}