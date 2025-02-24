#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
#define int long long
using namespace std;
using LL = long long;
using VI = vector<int>;
const int mod = 1e9 + 7;

LL qpow(LL x, LL y){
    LL ret=  1;
    for(; y; y >>= 1) {
        if(y & 1) (ret = ret * x) %= mod;
        (x = x * x) %= mod;
    }
    return ret;
}

LL inv(int x) { return qpow(x, mod - 2) % mod; }

struct BIT {
    int n;
    vector<int> T;
    BIT(int _n) : n(_n + 1) ,T(_n + 5) {    };
    int lowbit(int x) {return x & -x;}
	void clear() {fill(T.begin(), T.end(), 0); }
    void add(int x, int v) {
        for(++x; x <= n; x += lowbit(x)) (T[x] += v) %= mod;
    }
    LL ask(int x) {
        LL res = 0;                                 // 不赋初值见祖宗！！！！！ 
        for(++x; x > 0; x -= lowbit(x)) (res += T[x]) %= mod;
        return res;
    }
    LL query(int l, int r) { 
    	l++, r--;
        if(l > r) return 0;
        return ask(r) - ask(l - 1); 
    }
};
 
signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
 	int n; cin >> n; n++;
 	vector<int> A(n + 1);
	rep(i ,1, n - 1) cin >> A[i];
	A[n] = n; 
	BIT gg(n), tl = gg;	vector<BIT> tr(n + 1, tl);
	vector<vector<LL>> F(n + 1, vector<LL>(n + 1)), G = F;
	
	rep(i, 0, n) {
		rep(j, i + 1, n) G[i][j] = gg.query(A[i], A[j]), gg.add(A[j], 1);
		gg.clear();
	}
	per(i, n, 0) {
		tl.clear();
		rep(j, i + 1, n) {
			auto &f = F[i][j], g = G[i][j]; 
			int l = A[i], r = A[j];  
			if(!g) continue;
			f = ((tl.query(l, r) + tr[j].query(l, r) % mod) * inv(g) % mod + 1) % mod; 
			tl.add(A[j], f), tr[j].add(A[i], f);
		}
	}
	cout << (F[0][n] + mod) % mod << '\n';
    return 0; 
}