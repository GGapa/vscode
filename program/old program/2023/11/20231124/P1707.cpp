//P1707 Ë¢Ìâ±ÈÈü
// 2023-11-24 16:15
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int siz = 11;

ll n, mod = 100;
int p, q, r, t;
int u, v, w;
int x, y, z;

ll qmul(ll a, ll b) {
	ll an = 0, bs = a;
	while(b) {
		if(b & 1) an = (an + bs) % mod;
		bs = (bs + bs) % mod;
		b >>= 1;
	}
	return an;
}

struct Mat {
	ll a[15][15];
	Mat operator*(const Mat& ad) const {
		Mat c;
		for(int i = 1; i <= siz; i++) 
			for(int j = 1; j <= siz; j++) {
				c.a[i][j] = 0;
				for(int k = 1; k <= siz; k++)
					c.a[i][j] = (c.a[i][j] + qmul(a[i][k], ad.a[k][j])) % mod;
			}
		return c;
	}
}ans, base;

void init() {
	base.a[1][2] = base.a[1][3] = base.a[1][4] = base.a[2][1] = base.a[2][3] = base.a[2][5] = base.a[3][1] = base.a[3][2] = base.a[3][6] = base.a[7][7] = base.a[8][3] = base.a[8][8] = base.a[9][1] = base.a[9][7] = base.a[9][8] = base.a[9][9] = base.a[10][2] = base.a[11][3] = 1;
	base.a[8][7] = base.a[9][3] = 2;
	base.a[1][1] = p;
	base.a[2][2] = u;
	base.a[3][3] = x;
	base.a[4][1] = q;
	base.a[5][2] = v;
	base.a[6][3] = y;
	base.a[7][1] = r;
	base.a[8][1] = t;
	base.a[10][10] = w;
	base.a[11][11] = z;
	ans.a[1][1] = ans.a[1][2] = ans.a[1][3] = 3;
	ans.a[1][4] = ans.a[1][5] = ans.a[1][6] = ans.a[1][7] = ans.a[1][8] = ans.a[1][9] = 1;
	ans.a[1][10] = w;
	ans.a[1][11] = z;
}

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cout.tie(0);
//	freopen("akioi.in", "r", stdin);
//	freopen("akioi.out", "w", stdout);
	cin >> n >> mod;
	cin >> p >> q >> r >> t;
	cin >> u >> v >> w;
	cin >> x >> y >> z;	
	init();
	if(n < 2) {
		cout << "nodgd 1\n"
		<< "Ciocio 1\n"
		<< "Nicole 1";
		return 0;
	}
	n -= 2;
	while(n) {
		if(n & 1) ans = ans * base;
		base = base * base;
		n >>= 1;
	}
	cout << "nodgd " << ans.a[1][1] << "\nCiocio " << ans.a[1][2] << "\nNicole " << ans.a[1][3];
	return 0;
}


