#include <bits/stdc++.h>
using namespace std;
const int N = 100 + 5;
typedef long long ll;

int n, m, q;

struct Mat {
    int x, y;
    ll a[N][N];

    Mat operator*(const Mat &tmp) const {
        Mat c;
        c.x = x, c.y = tmp.y;
        for(int i = 1; i <= x; i++)
            for(int j = 1; j <= tmp.y; j++) {
                c.a[i][j] = 0;
                for(int k = 1; k <= y; k++) 
                    c.a[i][j] ^= a[i][k] * tmp.a[k][j];
            }
        return c;
    }
};
Mat mat[35], f;
ll a[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> q;
    for(int i = 1; i <= n; i++) cin >> a[i];
    mat[0].x = mat[0].y = n;
    for(int i = 1, u, v; i <= m; i++) {
        cin >> u >> v;
        mat[0].a[u][v] = mat[0].a[v][u] = 1;
    }
    for(int i = 1; i <= 32; i++) 
        mat[i] = mat[i - 1] * mat[i - 1];
    while(q--) {
        ll x;
        cin >> x;
        f.x = 1; f.y = n;
        memcpy(f.a[1], a, sizeof(f.a[1]));
        for(int i = 0; i <= 32; i++) {
            if((x >> i) & 1) 
                f = f * mat[i];
        }
        cout << f.a[1][1] << '\n';
    }
    return 0;
}
/*
倍增适合于各种各样的优化，非常实用
快速幂也算是二进制拆分，二进制拆分可以用于快速幂的预处理，还能用于喝果汁那道题
像这种和步数有关的题，应该联想到邻接矩阵，邻接矩阵虽然不常用，但是依然很重要
P6569 [NOI Online #3 提高组] 魔法值
*/