#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int N = 1000 + 5;

int n;
int x[N], y[N], S[N], T[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    rep(i, 1, n) {
        cin >> x[i] >> y[i];
        S[i] = x[i] + 1;T[i] = y[i] + 1;
    }
    int ans = INT_MAX;
    rep(i, 1, n) rep(j, 1, n) {
        int s = S[i], t = T[j];
        int a1, a2, a3, a4; a1 = a2 = a3 = a4 = 0;
        rep(k, 1, n) {
            a1 += (x[k] < s && y[k] < t); a2 += (x[k] < s && y[k] > t);
            a3 += (x[k] > s && y[k] < t); a4 += (x[k] > s && y[k] > t);
        }
        ans = min(ans, max({a1, a2, a3, a4}));
    }
    cout << ans << '\n';
    return 0;
}