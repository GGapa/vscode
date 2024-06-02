// E
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, q; cin >> n >> q;
    vector<ll> lt(n + 1), A(n + 1), S(q + 1);
    int si = 0;
    for(int i = 1, x; i <= q; i++) {
        cin >> x;
        si += (lt[x] == 0) - (lt[x] != 0);
        if(lt[x]) {
            A[x] += S[i - 1] - S[lt[x] - 1];
            lt[x] = 0;
        }
        else {
            lt[x] = i;
        }
        S[i] = S[i - 1] + si;
    }
    rep(x, 1, n) if(lt[x]) A[x] += S[q] - S[lt[x] - 1];
    rep(i, 1, n) cout << A[i] << " \n"[i == n];
    return 0;
}