#include <cstdio>
using namespace std;
const int N = 1e5 + 5,P = 998244353;
inline int qpow(int a,int b) { int res = 1;while(b) {if(b&1) res = 1ll * res * a % P;a = 1ll * a * a % P;b >>= 1;} return res;}
struct modint {
	int z;
	modint(){z = 0;}
	modint(const int _z): z(_z){}
	modint& operator = (const int &rhs) { z = rhs % P; return *this;}
	modint operator + (const modint &rhs) const { return modint(z + rhs.z >= P ? z + rhs.z - P : z + rhs.z);}
	modint operator - (const modint &rhs) const { return modint(z - rhs.z < 0 ? z - rhs.z + P : z - rhs.z);}
	modint operator * (const modint &rhs) const { return modint(1ll * z * rhs.z % P);}
	modint Inv() const { return modint(qpow(z,P - 2));}
	modint operator / (const modint &rhs) const { return modint(1ll * z * qpow(rhs.z,P - 2) % P);}
	modint& operator += (const modint &rhs) { return (*this = *this + rhs);}
	modint& operator -= (const modint &rhs) { return (*this = *this - rhs);}
	modint& operator *= (const modint &rhs) { return (*this = *this * rhs);}
};
struct Func {
	modint K,B;
	Func(){K = 0;B = 0;}
	explicit Func(modint _K,modint _B) { K = _K;B = _B;}
	Func operator + (const Func &rhs) const { return Func(K + rhs.K,B + rhs.B);}
	Func operator - (const Func &rhs) const { return Func(K - rhs.K,B - rhs.B);}

	Func operator * (const modint &rhs) const { return Func(K * rhs,B * rhs);}
	Func operator / (const modint &rhs) const { return Func(K / rhs,B / rhs);}

	friend Func operator * (const modint &lhs,const Func &f) { return f * lhs;}
	Func(const modint &x) { K = 0;B = x;}
};
int n,m,Q;
modint Base;
Func fc[N];
modint f[N];
inline modint P3(int x) { return modint(x) * modint(1ll * (n - 2) * m + x);}
inline modint P2(int x) { return Base - (modint(m - x) * modint(1ll * (n - 2) * m + x + x));}
inline modint P1(int x) { return modint(m - x) * modint(m - x);}
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);
	Base = modint(1ll * m * (n - 1) * m);
	// fc[0].K = 1;fc[0].B = 0;
	// fc[1] = (P2(0) * fc[0] - Base / modint(n)) / P1(0);
	// for(int i = 1;i < m;i++)
	// 	fc[i + 1] = (P2(i) * fc[i] - P3(i) * fc[i - 1] - Base / modint(n)) / P1(i);
	// modint tk = fc[m].K,tb = fc[m].B;
	// f[0] = (modint(0) - tb) / tk;
	f[0] = 0;
	f[1] = (P2(0) * f[0] - Base / modint(n)) / P1(0);
	for(int i = 1;i < m;i++)
		f[i + 1] = (P2(i) * f[i] - P3(i) * f[i - 1] - Base / modint(n)) / P1(i);
	for(int i = 0;i <= m;i++) printf("%d%c",f[i].z," \n"[i == m]);
	for(int _ = 1;_ <= Q;_++) {
		int x;modint ans;
		for(int i = 1;i <= n;i++) scanf("%d",&x),ans += f[x];
		ans -= f[m] - modint(n - 1) * f[0];
		printf("%d\n",ans.z);
	}
	return 0;
}
/* 0 499122176 748683263 249561077 */
