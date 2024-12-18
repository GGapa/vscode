#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, q; cin >> n >> q;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];

    string ans;
    for(int i = n, cnt = 0; i >= 1; i--) {
        if(A[i] <= cnt) ans += '1';
        else {
            if(cnt < q) ans += '1', cnt++;
            else ans += '0';
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T = 1;
    cin >> T;
    while(T--) solve();
    return 0;
}
/*
考虑一开始只参加比自己小的比赛最多能拥有多少个 problem
可以发现扣智商大概是越晚扣越好，*/