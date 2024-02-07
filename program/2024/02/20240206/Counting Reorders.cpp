//Counting Reorders
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 5000 + 5;

string s;
int n;
int C[N][N];

void init() {
    rep(i, 0, n) {
        C[i][0] = C[i][i] = 1;
        rep(j, 1, i) (C[i][j] = C[i - 1][j - 1] + C[i - 1][j]) %= mod;
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s; n = s.size();
    init();
    vector<int> F(26 + 2) ;
    vector<vector<int>> D(26 + 2, vector<int>(n + 1));
    for(char c : s) F[c-  'a']++;
    D[0][0] = 1;
    for(int i = 0, top = 0; i < 26; top += F[i++]) {
            int c = F[i];
        if(c == 0) D[i + 1] = D[i];
        else 
            rep(j, 0, top) rep(k, 1, c) {
                (D[i + 1][j + k] += D[i][j] * C[j + k][k] % mod * C[c - 1][k - 1] % mod) %= mod;
    
            }
    }
    int ans = 0; 
    rep(i, 0, n) 
        ((ans += ((n - i) % 2 ? mod - 1 : 1) * D[26][i]))%= mod;
    cout << ans << '\n';
    return 0;
}