#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000000 + 5;

int pri[maxn], phi[maxn], mi[maxn], mu[maxn];
bitset<maxn> vis;

void init(){
	mu[1] = 1;
	for(int i = 2; i <= maxn - 5; i++) {
		if(!vis[i]) pri[++pri[0]] = i, mi[i] = i, phi[i] = i - 1, mu[i] = -1;
		for(int j = 1; j <= pri[0] && i * pri[j] <= maxn - 5; j++) {
			int tt = i * pri[j];
			vis[tt] = 1;
			mi[tt] = pri[j];
			if(i % pri[j] == 0) {
				phi[tt]	 = phi[i] * pri[j];
				break;
			}
			else phi[tt] = phi[i] * phi[pri[j]];
			mu[tt] = -mu[i];
		}
	}
}

int main() {
	freopen("a.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	printf("%d\n", mu[6]);
	
	return 0; 	
} 
