#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 150 + 5;
const int INF = 1e9;

int n;
struct Node {
	int x, y;
	double dis(const Node& b) {
		return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
	}
}a[N];
double G[N][N], mxdis[N], ban[N];
int belong[N];

void dfs(int x, int id) {
	belong[x] = id;
	rep(i, 1, n) if(G[x][i] != INF && !belong[i])	
		dfs(i, id);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	rep(i, 1, n)
		cin >> a[i].x >> a[i].y;
	rep(i, 1, n) {
		string s;
		cin >> s;
		rep(j, 0, s.length() - 1) {
			if(s[j] == '1') 
				G[i][j+1] = a[i].dis(a[j+1]);
			else 
				G[i][j+1] =INF;
		}
	}
	
	int id = 0;
	rep(i, 1, n) 
		if(!belong[i]) 
			dfs(i, ++id);
	
	rep(k, 1, n) 
		rep(i, 1, n) 
			rep(j, 1, n) {
				if(G[i][k] + G[k][j] < G[i][j])
				G[i][j] = G[i][k] + G[k][j];
		}
	
	rep(i, 1, n) {
		rep(j, 1, n) {
			if(G[i][j] < INF && i != j) 
				mxdis[i] = max(mxdis[i], G[i][j]);
			}
		ban[belong[i]] = max(ban[belong[i]], mxdis[i]);
	}
	
	double ans = INF, tmp = 0;
	rep(i, 1, n) {
		rep(j, i, n) {
			if(belong[i] != belong[j]) {
				tmp = max({ban[belong[i]], ban[belong[j]], mxdis[i] + mxdis[j] + a[i].dis(a[j])});
				ans = min(ans, tmp);
			}
		}
	}
	printf("%.6f", ans);
	return 0;
}


