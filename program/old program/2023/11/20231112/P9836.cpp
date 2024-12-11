// P9836 种树
// https://www.luogu.com.cn/problem/P9836?contestId=141594

#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
const int mod = 998244353;
const int maxn = 1e4 + 5;
#define int long long

int n, w, a[maxn], cnt[maxn];
priority_queue<int, vector<int>, greater<int>> q;
long long ans = 1;

void solve(int x, int sum) {
    for(int i = 1;  i<= n; i++) {
        cnt[i] = 1;
        while(a[i] % x == 0) cnt[i]++, a[i] /= x;   //对a[i]有关w的质因数进行分解
        q.push(cnt[i]);      //储存
    }
    while(sum) {
        int it = q.top();
        q.pop();
        q.push(it+1);sum--;       //+1 有多少个次幂加多少个，进行贪心操作。
    }
    for(int i = 1; i <= n; i++) ans = ans * q.top() % mod, q.pop();
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> w;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int i = 2; i * i <= w; i++) {
        if(w % i == 0) {
            int tmp = 0;
            while(w % i == 0) w /=i, tmp++;
            solve(i, tmp);      //质因子以及他的个数。
        }
    }
    if(w > 1) solve(w, 1);  //如果没有分解完
    for(int i = 1;  i<= n; i++) {
        for(int j = 2; j * j <= a[i]; j++){ //对a[i]进行质因数分解，处理之前还没有经过 w 处理过的质因子，说白了就是
            int tmp = 1;
            while(a[i] % j == 0) a[i] /=j, tmp++;
            ans = ans * tmp % mod;      
        }     
        if(a[i] > 1) ans = ans * 2 % mod;   //如果还有剩下的，可以证明(伪证)一定是一个质因子。
    }
    cout << ans << '\n';
    return 0;
}

/*
编程语言
C++14 (GCC 9)
代码长度
1.51KB
用时
110ms
内存
808.00KB
 GGapa

所属题目
P9836 种树
评测状态
Accepted
评测分数
100
提交时间
2023-11-12 11:17:49
*/