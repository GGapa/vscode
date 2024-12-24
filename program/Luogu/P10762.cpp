#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
using LL = long long;
using VI = vector<int>;
using AI = array<int, 2>;

constexpr int INF = 1e9;

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, m; cin >> n >> m;
	vector<AI> itv(n + 1);
	rep(i, 1, n) rep(j, 0, 1) cin >> itv[i][j];
	
	vector<int> tmp;
	rep(i, 1, n) rep(j, 0, 1) tmp.emplace_back(itv[i][j]);
	tmp.emplace_back(m); tmp.emplace_back(0);
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

	int mm = tmp.size();
	rep(i, 1, n) rep(j, 0, 1) itv[i][j] = lower_bound(tmp.begin(), tmp.end(), itv[i][j]) - tmp.begin() + 1;

	vector<vector<array<int, 3>>> G(mm + 1);
	rep(i, 1, n) {
		int u = itv[i][0], v = itv[i][1];
		if(u < v) G[u].push_back({v, 1, 0});
		else G[1].push_back({v, 1, i});
	} 
	rep(i, 2, mm) G[i].push_back({i - 1, 0, 0});
	
	priority_queue<AI, vector<AI>, greater<AI>> q;
	vector<int> dis(mm + 1, n + 1), co(mm + 1);
	q.push({0, 1}); dis[1] = 0;
	while(!q.empty()) {
		int x = q.top()[1], val = q.top()[0]; q.pop();
		for(auto i : G[x]) {
			if(dis[x] + i[1] < dis[i[0]]) {
				q.push({dis[i[0]] = dis[x] + i[1], i[0]});
				co[i[0]] = max(co[x], i[2]);
			}
		}
	}
	
	int ans = dis[mm];
	rep(i ,1, n) if(itv[i][0] > itv[i][1]) ans = min(ans, dis[itv[i][0]] + (co[itv[i][0]] != i));
	cout << (ans >= n + 1 ? -1 : ans)<< '\n';
	return 0;
}