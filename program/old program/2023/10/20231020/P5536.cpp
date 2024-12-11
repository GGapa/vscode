#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cstdio>
using namespace std;
const int maxn = 1e5 + 5;

int n, k, f[maxn], dep[maxn], mdep = 1, mid, mxdep[maxn], ans[maxn];
vector<int> G[maxn];

void dfs(int x, int fa) {
	f[x] = fa;
    mxdep[x] = dep[x];
	for(auto to : G[x]) {
		if(to == fa) continue;
		dep[to] = (dep[x] + 1);
		if(dep[to] > dep[mdep]) mdep = to;
		dfs(to, x);
        mxdep[x] = max(mxdep[x], mxdep[to]);
	}
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("ro++.in", "r", stdin);
    //freopen("rp++.in", "w", stdout);
    cin >> n >> k;
    for(int i = 2, u, v; i <= n; i++) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs(1, 0);
	dep[mdep] = 0;
	dfs(mdep, 0);
    mid = mdep;
    for(int i = 1; i <= dep[mdep] / 2; i++) mid = f[mid];
    dep[mid] = 0;
    memset(mxdep, 0, sizeof(mxdep));
    dfs(mid, 0);
    for(int i = 1; i <= n; i++) {
        ans[i] = mxdep[i] - dep[i];
    }
    sort(ans + 1, ans + 1 + n);
    int aans = 0;
    for(int i = 1; i <= n - k; i++) aans = max(aans, ans[i]);
    cout << aans + 1<< "\n";
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.21KB
用时
1.11s
内存
13.51MB
 GGapa

所属题目
P5536 【XR-3】核心城市
评测状态
Accepted
提交时间
2023-10-20 10:46:57
*/