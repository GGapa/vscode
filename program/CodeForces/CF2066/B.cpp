#include <bits/stdc++.h>
// #include <bits/extc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
// using namespace __gnu_pbds;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

void solve() {
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    A[0] = -1;
    int ans = n - count(A.begin() + 1, A.end(), 0);
    
    int idx = 0;
    for(int i = 1; i <= n; i++) if(A[i] == 0) {
        idx = i;
        break;
    }

    if(idx == 0) return cout << ans << '\n', void();

    int now = ans;
    {
        vector<int> B(1);
        rep(i, 1, n) if(A[i] || i == idx) B.emplace_back(A[i]);
        int m = (int)B.size() - 1;
        vector<int> mn(m + 1, INT_MAX), mex(m + 1);
        rep(i, 1, m) mn[i] = min(mn[i - 1], B[i]);
        vector<int> vis(n + 1);
        for(int i = m, it = 0; i >= 1; i--) {
            if(B[i] <= n) vis[B[i]] = 1;
            while(vis[it]) it++;
            mex[i] = it;
        }
        bool tag = 1;
        rep(i, 1, m - 1) if(mn[i] < mex[i + 1]) tag = 0;
        ans = max(ans, now + tag);
    }

    for(int i = n; i >= 1; i--) if(A[i] == 0) {
        idx = i;
        break;
    }

    {
        vector<int> B(1);
        rep(i, 1, n) if(A[i] || i == idx) B.emplace_back(A[i]);
        int m = (int)B.size() - 1;
        vector<int> mn(m + 1, INT_MAX), mex(m + 1);
        rep(i, 1, m) mn[i] = min(mn[i - 1], B[i]);
        vector<int> vis(n + 1);
        for(int i = m, it = 0; i >= 1; i--) {
            if(B[i] <= n) vis[B[i]] = 1;
            while(vis[it]) it++;
            mex[i] = it;
        }
        bool tag = 1;
        rep(i, 1, m - 1) if(mn[i] < mex[i + 1]) tag = 0;
        ans = max(ans, now + tag);
    }

    // int cnt = 0;
    // rep(i, 1, m - 1) if(B[i] < mx[i + 1]) cnt++;
    // ans = max(ans, ans - cnt + (n - it));

    cout << ans << '\n';

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
不要忘记计算加入 0 的数量和删除的前缀最小值数量。
mex 是单调的，如果一个数需要删去，那么计数一下
0 在后面只能跟上一个，不能够跟上 > 
1
6
4 3 3 2 1 0
*/