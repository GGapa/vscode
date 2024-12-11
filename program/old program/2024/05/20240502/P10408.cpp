// P10408 Apple
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long LL;
#define int long long
using VI = vector<int>;
const int AA = (1 << 10) - 1, BB = AA << 10;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    int top = (1 << n) - 1;
    vector<int> A(1 << 21), F(1 << 21);
    rep(i, 0, top) {
        cin >> A[i];
        F[i] = A[i];
    }
    for(int j = 1; j < AA; j <<= 1) {
        rep(i, 0, top) if(j & i) {
            F[i] += F[j ^ i];
        }
    }
    //------------------------------------------------
    for(int op, s, a; q-- && cin >> op >> s; ) {
        if(op == 1) {
            int ans = 0;
            int tb = (s & BB), ta = s & AA;
            for(int i = tb; i; i = ((i - 1) & tb)) {
                ans += F[ta | i];
            }
            ans += F[s & AA];
            cout << ans << '\n';
        }
        else {
            cin >> a;
            int cha = a - A[s];
            int ta = ((s & AA) ^ AA);
            for(int i = ta; i; i = ((i - 1) & ta)) {
                F[i | s] += cha;
            }
            F[s] += cha;
            A[s] = a;
        }
    }
    return 0;
}