/*
P8817 [CSP-S 2022] 假期计划
https://www.luogu.com.cn/problem/P8817
*/

#include <limits.h>
#include <iostream> 
#include <queue>
#include <vector> 
#include <cstring>
using namespace std;
const int maxn = 2500 + 5;
#define int long long

int n, m, k;
int a[maxn], dis[maxn];
bool used[maxn];
vector<int> G[maxn];
vector<int> arr[maxn];
bool bj[maxn];

void debug() {
    for(int i = 1; i <= n; i++) {
        for (int j = 0; j < arr[i].size(); j++) {
            cout << arr[i][j] << " \n"[j == arr[i].size() - 1];
        }
    }
}

void bfs(int it) {
	memset(used, 0, sizeof(used));
	queue<pair<int, int> > q;
	q.push(make_pair(it, k + 1));
	used[it] = true;
	while(!q.empty()) {
		int now = q.front().first;
		int step = q.front().second;
		q.pop();
		for(int i = 0; i < G[now].size(); i++) {
			if(!used[G[now][i]]) {
                if(step - 1 > 0)q.push(make_pair(G[now][i], step - 1));
                arr[it].push_back(G[now][i]);
                if(G[now][i] == 1 && it != 1) 
                    arr[it].push_back(n + 1);
                used[G[now][i]] = true;
            }
		}
	}
}


void Dijkstra() {
    priority_queue <pair<int, int> > q;
    q.empty();
	q.push(make_pair(0, 1));
	dis[1] = 0;
	while(!q.empty()) {
		int now = q.top().second;
		int s = q.top().first;
        q.pop();
        if(bj[now]) continue;
        bj[now] = true;
        for(int i = 0; i < arr[now].size(); i++) {
            if(s + arr[now][i] > dis[arr[now][i]]) {
                dis[arr[now][i]] = s + arr[now][i];
                if(!bj[arr[now][i]])q.push(make_pair(dis[arr[now][i]], arr[now][i]));
            }
        }
	}
}

signed main() {
	ios::sync_with_stdio(0)	;
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k; 
	for(int i = 2; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) {
		bfs(i);
	}
    Dijkstra();
    cout << dis[n + 1] << endl;
} 