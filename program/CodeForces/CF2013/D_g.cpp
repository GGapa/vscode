#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n; cin >> n;
    vector<LL> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    vector<array<LL, 2>> q;
    per(i, n, 1) {
        LL S = A[i], cnt = 1;
        while(!q.empty()) {
            LL x = q.back()[0], y = q.back()[1];
            if(x / y > S / cnt) break;
            q.pop_back();
            S += x, cnt += y;
        }
        q.push_back({S, cnt});
    }
    cout << (q.front()[0] + q.front()[1] - 1) / q.front()[1]  - q.back()[0] / q.back()[1] << '\n'; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
//时间复杂度分析错了？其实这里并不需要二分，因为在队列里面根本不用放具体的值是多少，而且就算放了，也最多会产生 2n 个元素，且每个元素至多被 pop 一次。