#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string a, b; cin >> a >> b;
    reverse(a.begin(), a.end()); reverse(b.begin(), b.end());
    int n = a.size(), m = b.size();
    a = " " + a, b = " " + b;
    vector<VI> F(n + 1, VI(m + 1));
    vector<int> G(m + 1, 0); 
    unordered_map<int, int> H;
    rep(i, 1, n) {
        rep(j, 1, m) if(a[i] == b[j]) {
            auto &f = F[i][j];
            if(H[i - j] != 0 || i - j == 0)f = max(H[i - j] + 2, f);
            f = max(f, G[j - 1] + 1);
            H[i - j] = max(H[i - j], f);
        } 
        rep(j, 1, m) G[j] = max({G[j - 1], F[i][j], G[j]});
    }
    cout << G[m] << '\n';
    return 0;
}