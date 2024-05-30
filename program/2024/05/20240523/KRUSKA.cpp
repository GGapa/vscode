#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 200 + 5;

char A[N][N][8];
int F[N][N][4][8], G[N][N][4][8];	//记录 day 和 转向 
const int fx[4] = { 0, 1, 0, -1 }; 
const int fy[4] = { 1, 0, -1, 0 };

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
	int n, k; cin >> n >> k;
	int m; cin >> m;
	for(int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		cin >> A[x][y];
	}
	int x, y, f, d; x = y = 1; f = d = 0;
	int tu = 0;
	ll ans = 0;
	memset(F, -1, sizeof(F)), memset(G, -1, sizeof(G));
	while(1) {
		if(A[x][y][d] == 'L' ) f = (f + 3) % 4, ++tu;
      	if(A[x][y][d] == 'R' ) f = (f + 1) % 4, ++tu;
      	if(x + fx[f] < 1 || x + fx[f] > n || y + fy[f] < 1 || y + fy[f] > n) f = (f + 2) % 4, ++tu;
      	if(F[x][y][f][d] != -1) {
      		int ta = ans - F[x][y][f][d]; 
      		int tk = tu - G[x][y][f][d];
      	    int dl = k - tu;
            ans += 1ll * dl / tk * ta;
            tu += 1ll * dl / tk * tk;
		}
        F[x][y][f][d] = ans;
        G[x][y][f][d] = tu;
        if(tu >= k) break;
        ans++;
        x += fx[f]; y += fy[f];
        d = (d + 1) % 7;
	}
    cout << ans << '\n';
    return 0;
}