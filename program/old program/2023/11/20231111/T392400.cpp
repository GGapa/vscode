#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int mod = 998244353;

int n, w;
int a[maxn], dp[maxn][maxn], pf[1000];
bitset<maxn> vis;
int pri[maxn], mi[maxn];

int getf(int x) {
	int si = sqrt(x), sum = 0;
	for(int i = 1; i <= si; i++) 
		if(x % i == 0) sum++;
	return sum * 2;
}



void init() {
	int si = sqrt(w);
	for(int i = 1; i <= si; i++)
		if(w % i == 0) {
			pf[++pf[0]] = i;
			pf[++pf[0]] = w / i;
		}
	sort(pf + 1, pf + 1 + pf[0]);
}

int main() {
 	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> w;
	init();
	for(int i = 1; i <= pf[0]; i++) cout << pf[i] << endl;
	for(int i = 1; i <= n; i++) cin >> a[i], dp[1][i] = getf(a[i]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= pf[0]; j++) {
			dp[i][j] = 
		}
	}
	return 0;
}	
