// P3387 【模板】缩点
// https://www.luogu.com.cn/problem/P3387

#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;
vector<int> vec[maxn];
int n, m;
int A[maxn];
int dfn[maxn], low[maxn], T;
int stk[maxn], top;
bool ins[maxn];
int S[maxn], C; //C记录强连通分量的个数
int in[maxn];
int f[maxn], sum[maxn];
queue<int> q;
vector<int> G[maxn]; 

void dfs(int x)
{
    dfn[x] = low[x] = ++T;
    stk[++top] = x;
    ins[x] = true;
    for (auto y : vec[x])
    {
        if (dfn[y] == 0)
        {
            dfs(y);
            low[x] = min(low[x], low[y]);
        }
        else if (ins[y])
            low[x] = min(low[x], dfn[y]);
    }
    if (dfn[x] == low[x])
    {
        ++C;
        while (stk[top] != x)
        {
            int p = stk[top--];
            ins[p] = false;
            S[p] = C;
            sum[C] += A[p];
        }
        ins[x] = false;
        S[x] = C;
        sum[C] += A[x];
        top--;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> A[i];
    for (int i = 1, x, y; i <= m; i++)
    {
        cin >> x >> y;
        vec[x].push_back(y);
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i])
            dfs(i);
    /*
    for (int i = 1; i <= C; i++)
        G[i].reserve(10);
    */
    for (int i = 1; i <= n; i++)
    {
        for (auto j : vec[i])
        {
            if (S[i] != S[j])
            {
                G[S[i]].push_back(S[j]);
                in[S[j]]++;
            }
        }
    }
    for (int i = 1; i <= C; i++)
    {
        if (!in[i])
            q.push(i), f[i] = sum[i];
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (auto i : G[u])
        {
            f[i] = max(f[i], f[u] + sum[i]);
            --in[i];
            if (!in[i])
                q.push(i);
        }
    }
    int ans = 0;
    for (int i = 1; i <= C; i++)
    {
        ans = max(ans, f[i]);
    }
    cout << ans << endl;
    return 0;
}