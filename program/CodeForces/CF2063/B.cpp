#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, l, r; cin >> n >> l >> r;
    vector<int> A(n + 1), B;
    rep(i, 1, n) cin >> A[i];
    rep(i, l, r) B.emplace_back(A[i]);
    sort(B.begin(), B.end(), greater<int>());


    LL sum = accumulate(B.begin(), B.end(), 0ll), ans = sum;
    {
        vector<int> tmp;
        rep(i, r + 1, n) tmp.emplace_back(A[i]);
        sort(tmp.begin(), tmp.end());
        LL res = sum;
        for(int i = 0, j = 0; i < tmp.size() && j < B.size(); i++, j++) if(tmp[i] < B[j]) res += tmp[i] - B[j];
        ans = min(ans, res);
    }
    {
        vector<int> tmp;
        rep(i, 1, l - 1) tmp.emplace_back(A[i]);
        sort(tmp.begin(), tmp.end());
        LL res = sum;
        for(int i = 0, j = 0; i < tmp.size() && j < B.size(); i++, j++) if(tmp[i] < B[j]) res += tmp[i] - B[j];
        ans = min(ans, res);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}