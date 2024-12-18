#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, t; cin >> n >> t;
    vector<VI> A(n + 1, VI(n + 1));
    vector<int> a(n + 1), b(n + 1), c(2 * n + 1), d(2 * n + 1);
    for(int o = 1, X; o <= t; o++) {
        cin >> X;
        int x = (X - 1) / n + 1, y = (X - 1) % n + 1;
        if(!A[x][y]) {
            a[x]++, b[y]++;
            c[x + y]++, d[x - y + n]++;
        }
        if(a[x] == n || b[y] == n || c[x + y] == n || d[x - y + n] == n) return cout << o << '\n', 0;
        A[x][y] = 1;
    }
    cout << -1 << '\n';
    return 0;
}