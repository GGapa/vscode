/*
P2419 [USACO08JAN] Cow Contest S
https://www.luogu.com.cn/problem/P2419
*/
#include <iostream>
using namespace std;
const int maxn = 100 + 5;

int n, m;
int G[maxn][maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        G[a][b] = 1;
    }
    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                G[i][j] |= G[k][j] & G[i][k];
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        bool flag = 1;
        for(int j = 1; j <= n; j++) {
            if(i != j) {
                if(G[i][j] || G[j][i]) {
                    continue;
                }
                flag = 0;
                break;
            }
        }
        ans += flag;
    }
    cout << ans << "\n";
    return 0;
}