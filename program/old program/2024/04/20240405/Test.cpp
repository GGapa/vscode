// Test
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using VI = vector<int>;
typedef long long ll;

signed main() {
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k, q; cin >> n >> k >> q;
    vector<int> F(n + k + 1), S(n + k + 1), T(n + k + 1);
    for(int i = 1, x; i <= n ; i++) 
        cin >> x, F[x]++;
    T = F;
    rep(i, 1, n) cout << F[i] << " ";
    cout << '\n';
    rep(i, 1, n) {
        for(int j = i + 1; F[i] > 1 && j - i <= k; j++) if(T[j] == 0) {
            T[j]++, F[i]--, T[i]--;
        }
        S[i] = S[i - 1] + (T[i] == 0) ;
    }
    rep(i, 1, n) cout << T[i] << " ";
    cout << '\n';
    for(int i = 1, x, y; i <= q; i++) 
        cin >> x >> y, cout << (S[y] == S[x - 1] ? "YES\n" : "NO\n");
    return 0;
}