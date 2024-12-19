#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;

constexpr int N = 21, mod = 1e9 + 7;

int F[N][N][N][N][N][N], G[N][N][N][N][N][N];


void solve() {
    int n; cin >>n;
    string s; cin >> s; s = " " + s;
    F[0][0][0][0][0][0] = 1;
    rep(i, 1, n * 3) {
        for(int a = 0; a <= i && a * 2 <= 3 * n - i + 1; a++) for(int b = 0; a + b <= i && (a + b) * 2 <= 3 * n - i + 1; b++) 
            for(int c = 0; a + b + c <= i && (a + b + c) * 2 <= 3 * n - i + 1; c++) for(int d = 0; a + b + c + d * 2 <= i && (a + b + c) * 2 + d <= 3 * n - i + 1; d++) 
                for(int e = 0; a + b + c + (d + e) * 2 <= i && (a + b + c) * 2 + d + e <= 3 * n - i + 1; e++) for(int f = 0; a + b + c + (d + e + f) * 2 <= i && (a + b + c) * 2 + d + e + f <= 3 * n - i + 1; f++) {
                    // auto &t = G[a][b][c][d][e][f];
                    if(s[i] == '0' || s[i] == '1') {
                        if(a) (G[a][b][c][d][e][f] += F[a - 1][b][c][d][e][f]) %= mod;
                        if(e) (G[a][b][c][d][e][f] += 1ll * F[a][b + 1][c][d][e - 1][f] * (b + 1) % mod) %= mod;
                        (G[a][b][c][d][e][f] += 1ll * F[a][b][c][d][e][f + 1] * (f + 1) % mod) %= mod;
                    }
                    if(s[i] == '0' || s[i] == '2') {
                        if(b) (G[a][b][c][d][e][f] += F[a][b - 1][c][d][e][f]) %= mod;
                        if(f) (G[a][b][c][d][e][f] += 1ll * F[a][b][c + 1][d][e][f - 1] * (c + 1) % mod) %= mod;
                        (G[a][b][c][d][e][f] += 1ll * F[a][b][c][d + 1][e][f] * (d + 1) % mod) %= mod;
                    }
                    if(s[i] == '0' || s[i] == '3') {
                        if(c) (G[a][b][c][d][e][f] += F[a][b][c - 1][d][e][f]) %= mod;
                        if(d) (G[a][b][c][d][e][f] += 1ll * F[a + 1][b][c][d - 1][e][f] * (a + 1) % mod) %= mod;
                        (G[a][b][c][d][e][f] += 1ll * F[a][b][c][d][e + 1][f] * (e + 1) % mod) %= mod;
                    }
                    // if(t) cout << t << " " << i << " " << a << " " << b << " " << c << " " << d << " " << e << " " << f << '\n'; 0        
                }
        for(int a = 0; a <= i && a * 2 <= 3 * n - i + 1; a++) for(int b = 0; a + b <= i && (a + b) * 2 <= 3 * n - i + 1; b++) 
            for(int c = 0; a + b + c <= i && (a + b + c) * 2 <= 3 * n - i + 1; c++) for(int d = 0; a + b + c + d * 2 <= i && (a + b + c) * 2 + d <= 3 * n - i + 1; d++) 
                for(int e = 0; a + b + c + (d + e) * 2 <= i && (a + b + c) * 2 + d + e <= 3 * n - i + 1; e++) for(int f = 0; a + b + c + (d + e + f) * 2 <= i && (a + b + c) * 2 + d + e + f <= 3 * n - i + 1; f++)
                    F[a][b][c][d][e][f] = G[a][b][c][d][e][f], G[a][b][c][d][e][f] = 0;   
    }
    LL mul = 1;
    rep(i, 1, n) (mul *= i) %= mod;
    cout << 1ll * F[0][0][0][0][0][0] * mul % mod << '\n';
    for(int a = 0; a <= 3 * n && a <= n && a * 2 <= 3 * n; a++) for(int b = 0; a + b <= 3 * n && b <= n && b * 2 <= 3 * n ; b++) 
            for(int c = 0; a + b + c <= 3 * n && c <= n && c * 2 <= 3 * n ; c++) for(int d = 0; a + b + c + d <= 3 * n && a + d <= n && d <= 3 * n ; d++) 
                for(int e = 0; a + b + c + d + e <= 3 * n && b + e <= n && e <= 3 * n ; e++) for(int f = 0; a + b + c + d + e + f <= 3 * n && c + f <= n && f <= 3 * n ; f++) F[a][b][c][d][e][f] = 0;
}

signed main() {
    // freopen("P8366.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n = 20; int ans = 0;
    int T = 1; 
    cin >> T;
    while(T--) solve();
    return 0;
}