//P1376 [USACO05MAR] Yogurt factory 机器工厂
//https://www.luogu.com.cn/problem/P1376
#include <iostream>
using namespace std;
const int maxn = 1e4 + 5;
#define int long long 
int n, s;
int ans = 0;
int C[maxn], Y[maxn];
bool used[maxn];
signed main() {
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> C[i] >> Y[i];
    }
    for(int i = 1; i <= n; i++) {
        for(int j = i; j <= n; j++) {
            if(used[j]) continue;
            if(C[j] >= s * (j - i) + C[i]) {
                ans += (s * (j - i) + C[i]) * Y[j];
                used[j] = true;
            }
        }
    }
    cout << ans << endl;
    return 0;
    return 0;
}