#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> A(n + 1) ;
    rep(i, 1, n) cin >> A[i];
    auto calc = [&](int x) {
        LL ret = 0, it = 0, cnt = 0;
        map<int, int> mp;
        rep(i, 1, n) {
            mp[it]++;
            if(A[i] >= x) ret += mp[it++];
            else ret -= mp[--it];
            cnt += ret;
        }
        return cnt;
    };
    cout << calc(m) - calc(m + 1) << '\n';
    return 0;
}