// P1966 [NOIP2013 提高组] 火柴排队
// https://www.luogu.com.cn/problem/P1966
// 2023-11-13 10:27
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int mod = 1e8 - 3;
const int maxn = 1e5 + 10;
typedef long long ll;

int n;
struct Node {
    ll val;
    int it;
}a[maxn], b[maxn];
int f[maxn], t[maxn];
ll ans = 0;

void cmp(int l, int r) {
    if(l == r) return;
    int mid = l + r >> 1;
    cmp(l, mid); cmp(mid + 1, r);
    for(int i = l, j = l, k = mid + 1; i <= r; i++) {
        if(j == mid + 1)
            t[i] = f[k++];
        else if(k == r + 1)
            t[i] = f[j++], ans += k - mid - 1;
        else if(f[j] <= f[k]) 
            t[i] = f[j++], ans += k - mid - 1;
        else 
            t[i] = f[k++];
        ans %= mod;
    }
    for(int i = l; i <= r; i++) 
        f[i] = t[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("akioi.in", "r", stdin);
    // freopen("akioi.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i].val, a[i].it = i;
    for(int i = 1; i <= n; i++) cin >> b[i].val, b[i].it = i;
    sort(a + 1, a + 1 + n, [](const Node& x, const Node& y){return x.val < y.val;});
    sort(b + 1, b + 1 + n, [](const Node& x, const Node& y){return x.val < y.val;});
    for(int i = 1; i <= n; i++) f[a[i].it] = b[i].it;
    cmp(1, n);
    cout << ans << '\n';
    return 0;
}
/*
编程语言
C++14 (GCC 9)
代码长度
1.43KB
用时
159ms
内存
4.13MB
 GGapa

所属题目
P1966 [NOIP2013 提高组] 火柴排队
评测状态
Accepted
评测分数
100
提交时间
2023-11-13 10:51:52
*/