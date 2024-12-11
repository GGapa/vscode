/*
P1725 琪露诺
https://www.luogu.com.cn/problem/P1725
*/

#include <iostream>
#include <limits.h>
using namespace std;
const int maxn = 2e5 + 5;

int n, l, r, a[maxn], dp[maxn], h = 1, si = 1, que[maxn];
int ans = INT_MIN;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r;
    for(int i = 0 ; i <= n; i++) {
        cin >> a[i];
        dp[i] = INT_MIN;
    }
    dp[0] = 0;
    for(int i = l; i <= n; i++) {
        while(dp[i - l] >= dp[que[si]] && si >= h) si--;
        que[++si] = i - l;
        while(que[h] + r < i) h++;
        dp[i] = dp[que[h]] + a[i];
        if(i + r > n) {
            ans = max(ans, dp[i]);
        }
    }
    cout << ans << endl;
    return 0;
}