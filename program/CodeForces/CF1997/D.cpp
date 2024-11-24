#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
#define int long long
using LL = long long;
using VI = vector<int>;
const int N = 2e5 + 5;
const int INF = 1e18;

vector<int> G[N];
int A[N], F[N]; 
int n;

void dfs(int x, int fa) {
    if(G[x].empty()) return ;
    int t = INF;
    for(auto to : G[x]) {
        dfs(to, x);
        t = min(t, A[to]);
    }
    if(t >= INF) t = 0;
    if(x != 1)A[x] = max(A[x], (t + A[x]) / 2), A[x] = min(A[x], t);
    else A[x] += t;     
}

void solve() {
    cin >> n;
    rep(i, 1, n) cin >> A[i];
    for(int i = 2, j; i <= n; i++) 
        cin >> j, G[j].push_back(i);
    dfs(1, 0);
    // rep(i, 1, n) cout << A[i] << " \n"[i == n];
    cout << A[1] << '\n';
    rep(i, 1, n) vector<int>(0).swap(G[i]);
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while(T--) solve();
    return 0;
}
/*
给定一棵有根树，包含 \( n \) 个顶点。树中的顶点从 1 到 \( n \) 编号，根节点是顶点 1。第 \( i \) 个顶点上写着值 \( a_i \)。

你可以执行以下操作任意次数（可能为零次）：选择一个**至少有一个子节点**的顶点 \( v \)；将 \( a_v \) 增加 1；并且将 \( v \) 的子树中的所有顶点（不包括 \( v \) 自身）的 \( a_u \) 减少 1。然而，在每次操作之后，所有顶点上的值都应为非负数。

你的任务是计算使用上述操作后根节点上可能的最大值。

**输入:**
- 一棵树，包含 \( n \) 个顶点，根节点为 1。
- 每个顶点上的初始值 \( a_i \)。

**操作描述:**
1. 选择一个至少有一个子节点的顶点 \( v \)。
2. 将 \( a_v \) 增加 1。
3. 将 \( v \) 的子树中的所有顶点（不包括 \( v \) 自身）的 \( a_u \) 减少 1。
4. 确保所有顶点上的值都为非负数。

**目标:**
- 计算根节点上可能的最大值。

**提示:**
- 每个操作后，所有顶点的值都应为非负数。
- 可以进行任意多次操作，甚至是零次操作。

1
5
2 5 3 9 6
3 1 5 2
*/