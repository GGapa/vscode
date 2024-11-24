#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;

void solve() {
    int n, k; cin >> n >> k;
    vector<int> A(n + 1), B(n + 1);
    rep(i, 1, n) cin >> A[i];
    rep(i, 1, n) cin >> B[i];
    int tt, num = 0;
    int m1, mx; m1 = mx = 0;
    rep(i, 1, n) {
        if(B[i] && A[m1] < A[i]) m1 =i ;
        if(!B[i] && A[mx] <  A[i]) mx = i;
    }
    if(m1) {
        vector<int> p(1);
        rep(i, 1, n) if(i != m1) p.push_back(A[i]);
        sort(p.begin() + 1, p.end());
        num = A[m1] + k + p[n / 2];
    }
    if(mx) {
        vector<int> id(1);
        rep(i, 1, n) if(i != mx) id.push_back(i);
        sort(id.begin() + 1, id.end(), [&](const int &x, const int &y) {
            if(A[x] != A[y]) return A[x] < A[y];
            else return B[x] < B[y];
        });
        int md = n / 2;
        int cnt = 0;
        rep(c, 1, md) {
            int i = id[c];
            cnt += (B[i] == 0);
        }
        int l = 0, r = 3e9, ans = 0, st = 0;
        auto check = [&](int x) {
            LL sum = 0, cc = 0;
            per(c, n - 1, 1) {
                int i = id[c];
                if(A[i] >= x) 
                    {cc++; }
                else if(B[i]) 
                    sum += x - A[i], cc++; 
                if((n - cc) <= md) 
                    return sum <= k;
            }
            return false;
        };
        while(l <= r) {
            int mid = l + r >> 1;
            if(check(mid)) l = mid + 1, ans = mid;
            else r = mid - 1;
        }
        num = max(num, ans + A[mx]); 
    }
    cout << num << '\n'; 
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
结论 1：k 尽量给最大值用。
*/