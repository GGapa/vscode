#include <bits/stdc++.h>
#include <string>
#define rep(i, a, b) for(int i = (a), stOwrh = (b); i <= stOwrh; i++)
#define per(i, a, b) for(int i = (a), stOwrh = (b); i >= stOwrh; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
template<int siz>
using AI = array<int, siz>;

constexpr int N = 1e5 + 5;
LL n, m, T, top, s[N], c = 131, ha[N], hb[N], p[N], F[20][N];
string a, b;
LL getha(int l, int r) { return ha[r] - p[r - l + 1] * ha[l - 1]; }
LL gethb(int l, int r) { return hb[r] - p[r - l + 1] * hb[l - 1]; }

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> a; a += '?';
    n = a.size(); a =  " " + a;
    
    p[0] = 1;
    rep(i, 1, n) ha[i] = ha[i - 1] * c + a[i], p[i] = p[i - 1] * c;
    rep(i, 1, n) if (a[i] < 'a' || a[i] > 'z') s[++top] = i;
    cin >> T;
    while (T--) {
        cin >> b; b += '%';
        m = b.size(); b = " " + b;
        p[0] = 1;
        rep(i, 1, m) hb[i] = hb[i - 1] * c + b[i], p[i] = p[i - 1] * c;
        memset(F, 0, sizeof(F)), F[0][0] = 1;
        rep(i, 0, top) {
            if (a[s[i]] == '*')
                rep(j, 1, m) F[i][j] |= F[i][j - 1];
            rep(j, 0, m) if (F[i][j]) {
                LL la = s[i] + 1, ra = s[i + 1] - 1, lb = j + 1, rb = j + 1 + (ra - la);
                if (getha(la, ra) != gethb(lb, rb)) continue;
                if (a[s[i + 1]] == '?') F[i + 1][rb + 1] |= F[i][j];
                else F[i + 1][rb] |= F[i][j];
            }
        }
        cout << (F[top][m] ? "YES" : "NO") << '\n';
    }

    return 0;
}
