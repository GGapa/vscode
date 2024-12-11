#include <bits/stdc++.h>
using namespace std;
const int N = 8e2 + 5,P = 1e9 + 7;
inline void Plus(int &x,const int &y) { x += y;if(x >= P) x -= P;}
int n1,n2,n,Q,mx;
vector<int> G1[N],G2[N];
bool FLG = 1;
vector<pair<int,int> > Qs;
void dfs(int x1,int x2) {
	int d1 = 0,d2 = 0,n1 = x1,n2 = x2;
	while(G1[n1].size() == 1) ++d1,n1 = G1[n1][0];
	while(G2[n2].size() == 1) ++d2,n2 = G2[n2][0];
	Qs.emplace_back(d1 + 1,d2 + 1);
	if(G1[n1].size() != G2[n2].size()) return FLG = 0,void();
	for(int i = 0;i < G1[n1].size();i++)
		dfs(G1[n1][i],G2[n2][i]);
}
int S[N],C[N][N];
// inline void Add(int x) {
// 	for(int i = 0;i < mx;i++)
// 		for(int j = 0;j + x <= n;j++)
// 			Plus(dp[i + 1][j + x],dp[i][j]);
// }
// inline void Del(int x) {
// 	for(int i = mx;i >= 1;i--)
// 		for(int j = n;j >= x;j--)
// 			Plus(dp[i][j],P - dp[i - 1][j - x]);
// }
int dp1[N][N],dp2[N][N];
int main() {
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	cin >> n1 >> n2;
	for(int i = 2,x;i <= n1;i++)
		cin >> x,G1[x].push_back(i);
	for(int i = 2,x;i <= n2;i++)
		cin >> x,G2[x].push_back(i);
	dfs(1,1);
	n = max(n1,n2);
	for(auto i : Qs) mx = max(mx,i.first);
	C[0][0] = 1;
	for(int i = 1;i <= n;i++) {
		C[i][0] = C[i][i] = 1;
		for(int j = 1;j < i;j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % P;
	}
	cin >> Q;
	// printf("FLG:%d\n",FLG);
	// for(auto i : Qs) printf("Q:%d %d\n",i.first,i.second);
	if(!FLG) {
		for(int i = 1;i <= Q;i++)
			cout << 0 << endl;
		return 0;
	}
	// dp[0][0] = 1;
	int B = 12;
	for(int _ = 1;_ <= Q;_++) {
		int op,x;
		cin >> op >> x;
		// if(op == 1) Add(x); else Del(x);
		if(op == 1) ++S[x]; else --S[x];
		int has[N],tot = 0;
		for(int j = 0;j <= n;j++) if(S[j]) has[++tot] = j;
		int ps = 1;
		while(ps <= tot && has[ps] <= B) ++ps;
		for(int j = 0;j <= n;j++) for(int k = 0;k <= n;k++) dp1[j][k] = dp2[j][k] = 0;
		dp1[0][0] = dp2[0][0] = 1;
		for(int i = 1;i <= mx;i++)
			for(int j = 0;j <= n;j++)
				for(int k = 1;j + k <= n && k <= B;k++)
					if(S[k]) Plus(dp1[i][j + k],dp1[i - 1][j]);
		for(int i = 1;i <= min(mx,n / B);i++)
			for(int j = 0;j <= n;j++)
				for(int k = ps;j + has[k] <= n && k <= tot;k++)
						Plus(dp2[i][j + has[k]],dp2[i - 1][j]);
		// dp[0][0] = 1;
		// for(int i = 1;i <= mx;i++)
		// 	for(int j = 0;j <= n;j++)
		// 		for(int k = 1;k <= tot;k++)
		// 			if(j + has[k] <= n) Plus(dp[i][j + has[k]],dp[i - 1][j]);
		int ans = 1;
		for(auto it : Qs) {
			int x = it.first,y = it.second,sum = 0;
			for(int i = 0;i <= min(n / B,x);i++)
				for(int j = 0;j <= y;j++)
					Plus(sum,1ll * dp2[i][j] * dp1[x - i][y - j] % P * C[x][i] % P);
			ans = 1ll * ans * sum % P;
		}
		cout << ans << endl;
	}
	cerr << 1.0 * clock() / CLOCKS_PER_SEC << endl;
	return 0;
}