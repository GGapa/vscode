// P1772 [ZJOI2006] 物流运输
// https://www.luogu.com.cn/problem/P1772

#include <bits/stdc++.h>
using namespace std;
const int maxn = 100 + 5;
typedef long long ll;
#define int ll
int n, m, k, e, d, ans, lm;
vector<pair<int, int>> G[maxn];
int dis[maxn], fa[maxn], step[maxn];
int unable[maxn][maxn], isable[maxn];
bool use = false;
int dp[maxn], co[maxn][maxn];

// int way() {
// 	int it = m; bool flag = false;
// 	int cnt = 1;	
// 	while(it != 1) {
// 		if(step[cnt] != it) flag = true, use = true;
// 		step[cnt] = it;
// 		it = fa[it];
// 		cnt++;
// 	}
// 	return flag ? k : 0;
// }

void Dijkstra() {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	for(int i = 1; i <= m; i++) dis[i] = 2e9;
	memset(fa, 0, sizeof(fa));
	dis[1] = 0;
	fa[1] = 1;
	q.push(make_pair(0, 1));
	while(!q.empty()) {
		int x = q.top().second;
		q.pop();
		for(auto to : G[x]) {
			if(isable[to.first] == 1)  continue;
			int di = dis[x] + to.second;
			if(di < dis[to.first]) {
				dis[to.first] = di;
				q.push(make_pair(di, to.first)), fa[to.first] = x;
			}
		}
	}
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> e;
	for(int i = 1, u, v, w; i <= e; i++) {
		cin >> u >> v >> w;
		 G[u].push_back(make_pair(v, w));
		 G[v].push_back(make_pair(u, w));
	}
	cin >> d;
	for(int i = 1, id, a, b; i <= d; i++) {
		cin >> id >> a >> b;
		for(int j = a; j <= b; j++) {
			unable[id][j] = 1;
		}
	}
    for(int i = 1; i <= n; i++) {
        dp[i] = 2e9;
        for(int j = 1; j <= n; j++) {
            memset(isable, 0, sizeof(isable));
            for(int x = i; x <= j; x++) for(int y = 1; y <= m; y++) 
                isable[y] = unable[y][x] ? 1 : isable[y];
            Dijkstra();
            co[i][j] = dis[m];     //i->j 天不改变路线所需花费的money
        }
    }
    for(int i = 1; i <= n; i++) {
        dp[i] = co[1][i] * i;
        for(int j = i-1; j >= 0; j--) {
            dp[i] = min(dp[i], dp[j] + co[j+1][i] * (i-j) + k);
        }
    }
    cout << dp[n] << endl;
	return 0; 
}
/*
编程语言
C++14 (GCC 9)
代码长度
2.08KB
用时
601ms
内存
804.00KB
 GGapa

所属题目
P1772 [ZJOI2006] 物流运输
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 09:22:17
*/