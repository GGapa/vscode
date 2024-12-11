//P1395 会议
//https://www.luogu.com.cn/problem/P1395
#include <iostream>
#include <vector>

using namespace std;

const int N = 50005;

int d[N];
int f[N];
int n, cnt;
int size[N];
bool vis[N];
int head[N];

struct Edge {
    int to, nxt;
};

vector<Edge> edge(N << 1);

void add(int x, int y) {
    edge[++cnt] = {y, head[x]};
    head[x] = cnt;
}

void dfs1(int now) {
    size[now] = 1;
    for (int i = head[now]; i; i = edge[i].nxt) {
        int to = edge[i].to;
        if (d[to])
            continue;
        d[to] = d[now] + 1;
        dfs1(to);
        size[now] += size[to];
    }
}

void dfs(int now, int fa) {
    f[now] = f[fa] + n - 2 * size[now];
    for (int i = head[now]; i; i = edge[i].nxt) {
        int to = edge[i].to;
        if (to == fa)
            continue;
        dfs(to, now);
    }
}

int main() {
    cin >> n;
    for (int x, y, i = 1; i < n; i++) {
        cin >> x >> y;
        add(x, y);
        add(y, x);
    }
    d[1] = 1;
    dfs1(1);
    int maxn = 0, idx = 1;
    for (int i = 1; i <= n; i++)
        maxn += d[i];
    maxn -= n;
    f[1] = maxn;
    for (int i = head[1]; i; i = edge[i].nxt) {
        int to = edge[i].to;
        dfs(to, 1);
    }
    for (int i = 2; i <= n; i++) {
        if (f[i] < maxn)
            maxn = f[i], idx = i;
    }
    cout << idx << " " << maxn << endl;
    return 0;
}
