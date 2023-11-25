/**
 * @Problem      : 
 * @URL          : 
 * @Author       : GGapa
 * @Date         : 2023-11-17 16:46:10
 * @LastEditTime : 2023-11-17 16:52:58
**/
/**
 * @Problem      : AT_dp_d Knapsack 1
 * @URL          : https://www.luogu.com.cn/remoteJudgeRedirect/atcoder/dp_d
 * @Author       : GGapa
 * @Date         : 2023-11-17 16:46:10
 * @LastEditTime : 2023-11-17 16:52:54
**/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long ll;

int n, m;
int v[110], w[110];
ll f[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", 'w', stdout);
    cin >> n >> m;
    // memset(f, 0x3f, sizeof(f));
    for(int i = 1; i <= n; i++) cin >> v[i] >> w[i];
    for(int i = 1; i <= n; i++)
        for(int j = m; j >= v[i]; j--) 
            f[j] = max(f[j], f[j - v[i]] + w[i]);
    cout << f[m] << "\n";
    return 0;
}
//AC 100