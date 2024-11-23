#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

void solve() {
    int a, b, c; cin >> a >> b >> c;
    vector<int> A(a + 1), B(b + 1), C(c + 1);
    rep(i, 1, a) cin >> A[i];
    rep(i, 1, b) cin >> B[i];
    rep(i, 1, c) cin >> C[i];

    sort(A.begin() + 1, A.end()); 
    sort(B.begin() + 1, B.end());
    sort(C.begin() + 1, C.end());

    LL ans = LLONG_MAX;

    rep(i, 1, a) {
        int up = 3, x = A[i];
        rep(s, 0, up) {
            int y, z;
            if(s & 1) {
                auto it = lower_bound(B.begin() + 1, B.end(), x);
                if(it == B.end()) continue;
                y = *it;
            }
            else {
                auto it = lower_bound(B.begin() + 1, B.end(), x);
                if(it == B.begin() + 1) continue;
                y = *prev(it);
            }

            if(s >> 1 & 1) {
                auto it = lower_bound(C.begin() + 1, C.end(), x);
                if(it == C.end()) continue;
                z = *it;
            }
            else {
                auto it = lower_bound(C.begin() + 1, C.end(), x);
                if(it == C.begin() + 1) continue;
                z = *prev(it);
            }

            ans = min(ans, 1ll * (x - y) * (x - y) + 1ll * (y - z) * (y - z) + 1ll * (z - x) * (z - x));
        }
    }

    rep(i, 1, b) {
        int up = 3, x = B[i];
        rep(s, 0, up) {
            int y, z;
            if(s & 1) {
                auto it = lower_bound(A.begin() + 1, A.end(), x);
                if(it == A.end()) continue;
                y = *it;
            }
            else {
                auto it = lower_bound(A.begin() + 1, A.end(), x);
                if(it == A.begin() + 1) continue;
                y = *prev(it);
            }

            if(s >> 1 & 1) {
                auto it = lower_bound(C.begin() + 1, C.end(), x);
                if(it == C.end()) continue;
                z = *it;
            }
            else {
                auto it = lower_bound(C.begin() + 1, C.end(), x);
                if(it == C.begin() + 1) continue;
                z = *prev(it);
            }

            ans = min(ans, 1ll * (x - y) * (x - y) + 1ll * (y - z) * (y - z) + 1ll * (z - x) * (z - x));
        }
    }

    rep(i, 1, c) {
        int up = 3, x = C[i];
        rep(s, 0, up) {
            int y, z;
            if(s & 1) {
                auto it = lower_bound(A.begin() + 1, A.end(), x);
                if(it == A.end()) continue;
                y = *it;
            }
            else {
                auto it = lower_bound(A.begin() + 1, A.end(), x);
                if(it == A.begin() + 1) continue;
                y = *prev(it);
            }

            if(s >> 1 & 1) {
                auto it = lower_bound(B.begin() + 1, B.end(), x);
                if(it == B.end()) continue;
                z = *it;
            }
            else {
                auto it = lower_bound(B.begin() + 1, B.end(), x);
                if(it == B.begin() + 1) continue;
                z = *prev(it);
            }

            ans = min(ans, 1ll * (x - y) * (x - y) + 1ll * (y - z) * (y - z) + 1ll * (z - x) * (z - x));
        }
    }
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
答案一定存在于最近的两个之间，考虑状态压缩。
1
2 2 2
1 2
3 4
6 7
*/