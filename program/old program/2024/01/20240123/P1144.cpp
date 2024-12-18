#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
const int mod = 100003 ;
typedef pair<int ,int> pii;

int n, m, s = 1; 
vector<int> G[N];
int dep[N], ans[N];
void Dijkstra() {
	rep(i, 1, N - 5)  dep[i] = 2e9; 
	priority_queue<pii, vector<pii>, greater<pii>> q;
	dep[s] = 1; ans[s] = 1;
	q.push({0, s});
	while(!q.empty()) {
		int x = q.top().second; q.pop();
		for(auto to : G[x] ){
			if(dep[to] > dep[x] + 1) {
				dep[to] = dep[x] + 1;
				ans[to] = ans[x];
				q.push({dep[to], to});
				
			}
			else if(dep[to] == dep[x] + 1) ans[to] = (ans[to] + ans[x]) % mod;
		}
	}
	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	Dijkstra();
	rep(i, 1, n) cout << ans[i] << '\n';
	
	return 0;
}
