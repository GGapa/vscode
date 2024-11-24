#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
#define int long long
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> A(n + 1);
    rep(i, 1, n) cin >> A[i];
    for(int i = 1, x; i <= n; i++) 
        cin >> x, A[i] = -A[i] + x;
    ll ans = 0;
    auto work = [&](int l, int r) {
        rep(i, l, r) if(A[i] > 0) A[i] *= -1;
        if(l == r) return A[l] * -1;
        if(l == r + 1) return min(A[l], A[r]) * -1;

        vector<pair<int, int>> nd; 
        nd.push_back({0, 0});
        rep(i, l, r - 2) {
            int s = i + 1, t = i + 2;
            while(t < n && A[s] == A[t]) t++;
            if(A[i] > A[s] && A[s] < A[t]) nd.push_back({A[s], 2});
            if(A[i] < A[s] && A[s] > A[t]) nd.push_back({A[s], -2});
        }
        if(A[l] < A[l + 1]) nd.push_back({A[l], 2});
        if(A[r] < A[r - 1]) nd.push_back({A[r], 2});
        if(nd.size() == 1) nd.push_back({A[l], 2});
        sort(nd.begin(), nd.end());
        int cnt = 0;
        rep(i, 0, (int)nd.size() - 1) {
            auto p  = nd[i];
            if(i) {
                ans += max((cnt + 1) / 2, 1ll) * (p.first - nd[i - 1].first);
            }
            cnt += p.second;
        }
        return 0ll;
    };
    for(int l = 1, r = 1; r <= n && l <= n; l = r + 1) {
        r = l;
        while(r < n && A[l] * A[r + 1] > 0) r++;
        ans += work(l, r);
    }
    cout << ans << '\n';
    return 0;
}