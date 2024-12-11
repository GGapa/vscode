#include <bits/stdc++.h>
using namespace std;
const int maxn = 20000000 + 5;
typedef long long ll;

bitset<maxn> vis, tmp;
set<int> vis2;
int pri[maxn], mi[maxn], cnt = 0;
int p[1000], ans[1000], cnta;
int n;

void init(){
	for(int i = 2; i <= maxn - 5; i++) {
		if(!vis[i]) pri[++pri[0]] = i, mi[i] = i;
		for(int j = 1; j <= pri[0] && i * pri[j] <= maxn - 5; j++) {
			vis[i * pri[j]] = 1;
			mi[i * pri[j]] = pri[j];
			if(i % pri[j] == 0) break;
		}
	}
}

void dfs(int x, int y) {
//	cout << x << endl;
	if(y > cnt) {
		ans[++cnta] = x;
		vis2.insert(x);
		return ;
	}
	dfs(x*p[y],y+1);
	dfs(x,y+1);
}

int main() {
//	freopen("a.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	init();
	cin >> n; int maxx;
	for(int i = 1; i <= 1; i++) {
		int t = n; vis2.clear();
		cnt = 0, cnta = 0;
		while(t > 1) {
			p[++cnt] = mi[t];
			t /= mi[t] ;
		}
		dfs(1, 1);
		maxx = max(maxx, (int)vis2.size());
	}
	cout << maxx << "\n";
	return 0;
}
