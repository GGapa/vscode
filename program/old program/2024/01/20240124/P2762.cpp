#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); i++)
#define per(i, a, b) for(int i = (a); i >= (b); i--)
using namespace std;
typedef long long ll;
const int N = 1e7;

int n, m, s, t; 

struct edge {
	int v, val, nxt;
}e[N];
int head[N], cur[N], tot = 1;
int dep[N];

void add(int u, int v, int w) {
	e[++tot] = (edge){v, w, head[u]};
	head[u] = tot;
	e[++tot] = (edge){u, 0, head[v]};
	head[v] = tot;
}

bool bfs() {
	queue<int> q;
	memset(dep, 0, sizeof(dep));
	cur[s] = head[s];
	dep[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int u = q.front() ; q.pop();
		for(int i = head[u]; i; i = e[i].nxt) {
			int v = e[i].v;
			if(!dep[v] && e[i].val) {
				cur[v] = head[v];
				q.push(v);
				dep[v] = dep[u] + 1;
				if(t == v) return 1;
			}
		}
	}
	return dep[t];
}
int dfs(int u, int sum) {
//	cout << u << endl;
	if(u == t || sum == 0) return sum;
	int k, res = 0;
	for(int i = cur[u]; i && sum; i = e[i].nxt) {
		int v = e[i].v;
		cur[u] = i;
		if(e[i].val && dep[v] == dep[u] + 1) {
			k = dfs(v, min(sum, e[i].val));
			if(k == 0) dep[v] = 0;
			e[i].val -= k;
			e[i^1].val += k;
			sum -= k;
			res += k; 
		}
	}
	return res;
}

int dinic() {
	int tmp = 0;
	while(bfs()) tmp += dfs(s, INT_MAX);
	return tmp; 
} 


int main() {
    int n, m;
    scanf("%d%d", &m, &n);
    s = 0, t = n + m + 1;
    int sum = 0;
    for(int i = 1; i <= m; i++) {
        int x;
        char c;
        scanf("%d", &x);
        sum += x;
        add(s, n + i, x);
        while(1) {
            scanf("%d%c", &x, &c);
            add(n + i, x, 2e9);
            if(c=='\n' || c=='\r' || c == '\r\n')break;
        }
    }
    for(int i = 1; i <= n; i++) {
        int w;
        scanf("%d", &w);
        add(i, t, w);
    }
    sum -= dinic();
    for(int i = 1; i <= m; i++) {
        if(dep[i + n])
            printf("%d ",i);
    }
    printf("\n");
    for(int i = 1; i <= n; i++)
        if(dep[i])
            printf("%d ", i);
    printf("\n");
    printf("%d\n", sum);
    return 0;
}


