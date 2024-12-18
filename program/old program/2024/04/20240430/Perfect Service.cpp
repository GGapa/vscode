// UVA1218 Perfect Service
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a), stOwxc = (b); i <= stOwxc; i++)
#define per(i, a, b) for(int i = (a), stOwxc = (b); i >= stOwxc; i--)
using namespace std;
typedef long long ll;
using VI = vector<int>;
const int N = 10000 + 5;
const int INF = N  +5;
vector<VI> G(N);
vector<VI> F(N, VI(3));

int dp(int x, int fa, int ty) {
    auto &f = F[x][ty];
    if(f != -1) return f;
    f = 0;
    if(ty == 0) {
        for(auto to : G[x]) if(to != fa) {
            f += min(dp(to, x, 0), dp(to, x, 1));
        }
        f++;
    }
    else if(ty == 1) {
        for(auto to : G[x]) if(to != fa) {
            f += dp(to, x, 2);
        }
    }
    else {
        f = INF;
        for(auto to : G[x]) if(to != fa) {
            f = min(f, dp(x, fa, 1) - dp(to, x, 2) + dp(to, x, 0));
        }
    }
    return f;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    for(int n; cin >> n && n != -1; ) {
        fill(G.begin() + 1, G.begin() + 1 + n, VI(0));
        fill(F.begin() + 1, F.begin() + 1 + n, VI(3, -1));
        for(int u, v; cin >> u && u && u != -1; ) 
            cin >> v, G[u].push_back(v), G[v].push_back(u);
        cout << min(dp(1, 0, 2), dp(1, 0, 0)) << '\n';
    }
    return 0;
}

/*
还是 dp(x, fa, type) 
type = 1 ，他自己作为服务器
type = 2 ，他父亲作为服务器
type = 3 , 他自己不是服务器，他父亲不是服务器但是被照亮
*/

/*
还是 dp(x, fa, type) 
type = 1 其父亲作为服务器
type = 2 其父亲有服务器作为连接，此时 x 不能作为服务器
type = 3 其父亲没有连接，此时 x 只能作为服务器
还是假了
*/

/* 
假了
考虑定义 dp(x, fa, tpye) 代表节点 x 的 fa 其做不做为服务器, 和其有没有被照亮
作为 1 不做 0。
若他的父亲没有做那么这个节点一定做，若他的父亲做了，那么他的节点一定不做。
若他做了，则他的儿子一定不做，若他不做则他的儿子一定会做。
最小的服务器数量
*/


/*
10
10 9
4 10
2 4
3 2
1 9
5 1
6 5
8 3
7 1
-1
*/