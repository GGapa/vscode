#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e4 + 5;

int n, m;
int dfn[N], low[N], vis[N], belong[N], cnt, sum[N];
stack<int> s;
vector<int> G[N];

void tarjan(int x) {
    dfn[x] = low[x] = ++dfn[0];
    s.push(x);
    vis[x] = 1;
    for(auto to : G[x]) {
        if (!dfn[to]) {
            tarjan(to);
            low[x] = min(low[x], low[to]);
        }
        else if (vis[to]) low[x] = min(low[x], dfn[to]);
    }
    if (low[x] == dfn[x]) {
        cnt++;
        while(s.top() != x) {
        	belong[s.top()] = cnt;
        	sum[cnt]++;
        	vis[s.top()] = 0;
            s.pop();
        }
        belong[s.top()] = cnt;
        sum[cnt]++;
        vis[s.top()] = 0;
        s.pop();
    }
}

int main()  {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	rep(i, 1, m) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	rep(i, 1, n) if(!dfn[i]) tarjan(i);
	int ans = 0;
	rep(i, 1, cnt) if(sum[i] > 1) ans++;
	cout << ans << '\n';
	
	return 0;
}

