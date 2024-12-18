// Empty String
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int N = 5000 + 5;
#define int unsigned long long
int C[N][N];

void init(int n) {
	C[0][0] = 1;
	rep(i, 1, n) {
        C[i][0] = 1;
        rep(j, 1, i) C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
    }  
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	string s; cin >> s;
	int n = s.length();
    s.insert(0, " ");
	using VI = vector<int>;
	vector<VI> F(n + 10, VI(n + 10));
	init(N - 2);
    rep(i, 0, n) F[i + 1][i] = 1;
    per(i, n, 1) for(int j = i + 1; j <= n; j += 2) for(int k = i + 1; k <= j; k += 2) if(s[i] == s[k])
            (F[i][j] += F[i + 1][k - 1] * F[k + 1][j] % mod * C[(j - i + 1) / 2][(k - i + 1) / 2] % mod) %= mod;
    cout << F[1][n] % mod << '\n';    
    return 0;
}