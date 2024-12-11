#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tp = 15;
    vector<int> A(4);
    rep(i, 0 ,3) cin >> A[i];

    rep(s, 0, tp) {
        vector<int> cnt(2);
        rep(i, 0, 3) cnt[s >> i & 1] += A[i];
        if(cnt[0] == cnt[1]) return cout << "Yes\n", 0;
    }

    cout << "No\n";
    return 0;
}