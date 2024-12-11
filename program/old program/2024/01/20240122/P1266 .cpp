#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++) 
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 150 + 5;
typedef pair<double, pair<int, int>> piii;

int n, m, t, s = 0;
struct edge {
	int x, to, v, l;
}; 
vector<edge> G[N];
double dis[205][1005];
int vis[205][1005];
pair<int, int> from[205][1005];

void Dijkstra() {
	priority_queue<piii, vector<piii>, greater<piii>> q;
	rep(i, 0, n) rep(j, 0, 500) dis[i][j] = 2e9;
	dis[0][70] = 0;
	q.push({0, {0, 70}});
	while(!q.empty()) {
		pair<int, int> u = q.top().second;
		q.pop();
		if(vis[u.first][u.second]) 
			continue;
		vis[u.first][u.second] = 1;
		for(auto i : G[u.first]) {
			int v = i.to, sped = (i.v ? i.v : u.second);
			double time = (double)i.l / (double)sped;
			if(dis[u.first][u.second] + time < dis[v][sped]) {
				dis[v][sped] = dis[u.first][u.second] + time;
				from[v][sped] = u;
				q.push(make_pair(dis[v][sped], make_pair(v, sped)));
			}
		}
	}

}

void write(int x, int v) {
	if(x == 0) {
		cout << "0 ";
		return;
	}
	write(from[x][v].first, from[x][v].second);
	cout<< x << ' ';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> t;
	rep(i, 1, m) {
		int a, b, v,l;
		cin >> a >> b >> v >> l; 
		G[a].push_back(edge{a, b, v, l});
	}
	Dijkstra();
	int maxx = 0;
	for(int i = 1; i <= 500; i++)
		if(dis[t][i] < dis[t][maxx]) 
			maxx = i;
	write(t, maxx);
	
	return 0;
}
 
