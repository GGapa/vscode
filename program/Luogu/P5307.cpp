#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 1e6 + 5, mod = 1e9 + 7;

int F[2][301][2005], id[N], val[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int r, s, n; cin >> r >> s >> n; n--;
    vector<VI> A(r + 1, VI(s + 1));
    rep(i, 1, r) rep(j, 1, s) cin >> A[i][j];

    for(int i = 1; i <= n; i = n / (n / i) + 1) {
        val[++id[N - 1]] = n / i;
        id[val[id[N - 1]]] = id[N - 1];
    }

    F[1][1][id[n / A[1][1]]] = 1;
    for(int c = 1, i = 1, ni = 0; c <= r; c++, swap(i, ni)) {
        memset(F[ni], 0, sizeof(F[ni]));
        rep(j, 1, s) rep(k, 0, id[N - 1]) if(F[i][j][k]) {
            const int &f = F[i][j][k];
            if(c < r) (F[ni][j][id[val[k] / A[c + 1][j]]] += f) %= mod;
            if(j < s) (F[i][j + 1][id[val[k] / A[c][j + 1]]] += f) %= mod;
        }
    } 

    cout << F[r & 1][s][0] << '\n';
    return 0;
}