#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 998244353;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k; n--;
    vector<vector<LL>> F(k + 1, vector<LL>(n + 2)), C(n + 1); 
    rep(i, 0, n) {
        C[i].resize(i + 1);
        C[i][0] = C[i][i] = 1;
        rep(j, 1, i - 1 )  C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
    F[0][0] = 1;
    rep(i, 0, k - 1) rep(t, 0, n) {
		LL pw = qpow(k - i, t * (t - 1) / 2);   // 增加的边集中，
		LL step = qpow(k - i, t);   // 初始的点集中，可能的边权
	    rep(j, 0, n - t){   
			(F[i + 1][j + t] += F[i][j] * C[n - j][t] % mod * pw % mod) %= mod; 
            /*
                C[n - j][t] 从 n - j 条边，选出来 t 条变化

            */
			(pw *= step) %= mod;
		}
	}
    cout << F[k][n] << '\n';
    return 0;
}
/*
64 + 189 + 152 + 37
*/