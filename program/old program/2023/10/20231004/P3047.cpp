// P3047 [USACO12FEB] Nearby Cows G
#include <bits/stdc++.h>
using namespace std;
const int NN = 1e5 + 4, KK = 20 + 2;
int N, K, C[NN], D[NN][KK], F[NN][KK];
vector<int> G[NN];
#define _all(i, a, b) for (int i = (a); i <= (int)(b); ++i)
void dp(int u, int fa)
{ // D(u,d), 子树u中距离u为d的点权之和
    D[u][0] = F[u][0] = C[u];
    for (int v : G[u])
    {
        if (v == fa)
            continue;
        dp(v, u);
        _all(d, 1, K) D[u][d] += D[v][d - 1];
    }
}
void dpF(int u, int fa)
{ // F(u,d)整棵树距离u为d的点权和
    for (int v : G[u])
    { // 对于根节点u F(u,d) == D(u,d)
        if (v == fa)
            continue;
        _all(d, 1, K)
        {
            F[v][d] = D[v][d] + F[u][d - 1];
            if (d > 1)
                F[v][d] -= D[v][d - 2];
        }
        dpF(v, u);
    }
}
int main()
{
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> N >> K;
    for (int i = 1, u, v; i < N; i++)
        cin >> u >> v, G[u].push_back(v), G[v].push_back(u);
    _all(i, 1, N) cin >> C[i];
    dp(1, 1), copy(D[1], D[1] + K + 1, F[1]), dpF(1, 1);
    _all(i, 1, N) printf("%d\n", accumulate(F[i], F[i] + K + 1, 0));
    return 0;
}
/*
2023-10-04 15:34:02
编程语言
C++14 (GCC 9)
代码长度
1.15KB
用时
583ms
内存
27.74MB
*/