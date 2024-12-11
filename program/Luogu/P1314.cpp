// P1314 [NOIP2011 提高组] 聪明的质监员
// https://www.luogu.com.cn/problem/P1314
// 2023-11-12 20:52

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 200000 + 5;
typedef long long ll;
#define int ll
int n, m, s, x, y;
int w[maxn], v[maxn], sw[maxn], sv[maxn];
int l[maxn], r[maxn];
ll sum, ans = 2e18;

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n >> m >> s;
    for(int i = 1; i <= n; i++) cin >> w[i] >> v[i], y = max(w[i], y);
    for(int i = 1; i <= m; i++) cin >> l[i] >> r[i];
    y++;
    while(x < y) {
        memset(sw, 0, sizeof(sw));
        memset(sv, 0, sizeof(sv));
        int mid = (x + y)  >> 1;
        sum = 0;
        for(int i = 1; i <= n; i++) {
            if(w[i] >= mid) sw[i] = sw[i-1] + 1, sv[i] = sv[i-1] + v[i];
            else sw[i] = sw[i-1], sv[i] = sv[i-1];
        }
        for(int i = 1; i <= m; i++) 
            sum += (ll)(sv[r[i]] - sv[l[i]-1]) * (sw[r[i]] - sw[l[i]-1]);
        if(sum == s) {
            ans = 0;
            break;
        }
        ans = min(ans, abs(sum - s));
        if(sum > s) {
            x = mid + 1;
        }
        else if(sum < s) {
            y = mid;
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.39KB
用时
323ms
内存
9.56MB
 GGapa

所属题目
P1314 [NOIP2011 提高组] 聪明的质监员
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 21:28:36
*/