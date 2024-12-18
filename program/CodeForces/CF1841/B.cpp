#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<int> A;
    int tag = 0;
    for(int i = 1, x; i <= n; i++) {
        cin >> x;
        int ret = 0;
        if(A.empty())  ret = 1;
        else if(!tag && x >= A.back())  ret = 1;
        else if(!tag && x < A.back() && x <= A.front()) tag = 1, ret = 1;
        else if(tag && x >= A.back() && x <= A.front()) ret = 1;
        else ret = 0;
        if(ret) A.emplace_back(x);
        cout << ret;
    }
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