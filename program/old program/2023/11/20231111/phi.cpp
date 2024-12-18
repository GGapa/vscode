#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000000 + 5;

int pri[maxn], phi[maxn], mi[maxn];
bitset<maxn> vis;

void init(){
	for(int i = 2; i <= maxn - 5; i++) {
		if(!vis[i]) pri[++pri[0]] = i, mi[i] = i, phi[i] = i - 1;
		for(int j = 1; j <= pri[0] && i * pri[j] <= maxn - 5; j++) {
			vis[i * pri[j]] = 1;
			mi[i * pri[j]] = pri[j];
			if(i % pri[j] == 0) {
				phi[i * pri[j]]	 = phi[i] * pri[j];
				break;
			}
			else phi[i * pri[j]] = phi[i] * phi[pri[j]];
		}
	}
}

int main() {
	freopen("a.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	printf("%d\n", phi[20000000]);
	return 0; 	
} 
