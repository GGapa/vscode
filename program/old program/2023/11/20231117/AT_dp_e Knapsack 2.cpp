/**
 * @Problem      : AT_dp_e Knapsack 2
 * @URL          : https://www.luogu.com.cn/remoteJudgeRedirect/atcoder/dp_e
 * @Author       : GGapa
 * @Date         : 2023-11-17 16:19:28
 * @LastEditTime : 2023-11-17 16:43:33
**/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long ll;

int n, m, w[110], v[110], mxval;
ll f[1000006];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    memset(f, 0x3f, sizeof(f));
    cin >> n >> m;
    mxval = n * 1000;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i];
    f[0] = 0;
    for(int i = 1; i <= n; i++) 
        for(int j = mxval; j >= v[i]; j--) 
             f[j] = min(f[j], f[j - v[i]] + w[i]);
    for(int i = mxval; i; i--){
		if(f[i] <= m){
			cout << i;
			return 0;
		}
	}
    return 0;
}   
// AC 100
