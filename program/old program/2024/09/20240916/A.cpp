#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

signed main() {
    freopen("wind.in", "r", stdin);
    freopen("wind.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n; cin >> n;
    LL k; cin >> k;
    vector<int> A(n + 2);
    vector<pair<int, LL>> q(n + 5);
    vector<LL> rec(n + 2, -1);
    rep(i, 1, n) cin >> A[i];
    int l = 1, r = n;
    LL ans = 0;
    auto check = [&](int x) {
        if(rec[x] != -1) return rec[x];
        int head = 0, tail = 1;
        LL t;
        q[++head] = {0, 0};
        rep(i, 1, n + 1) {
            while(tail <= head && i - q[tail].first > x) tail++;
            t = q[tail].second + A[i];
            while(tail <= head && q[head].second > t) head--;
            q[++head] = {i, t};
        }
        return rec[x] = t;
    }; 
    while(r - l > 2) {
        int mid1 = l + (r - l + 1) / 3, mid2 = mid1 + (r - l + 1) / 3;
        if(abs(check(mid1) - k) <= abs(check(mid2) - k)) r = mid2;
        else l = mid1;
    }
    vector<int> F(n + 1); 

    LL mn = LLONG_MAX;
    rep(i, l, r) {
        LL t = check(i);
        if(abs(k - t) <= mn) mn = abs(k - t), ans = t;
    }
    cout << ans << '\n';
    return 0;
}